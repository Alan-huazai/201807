 ///
 /// @file    auto_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 18:34:12
 ///
 
#include <iostream>
#include <memory>
using std::auto_ptr;
using std::cout;
using std::endl;
class Point{
public:
	Point(int ix=0,int iy=0)
	:_ix(ix)
	 ,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
	void setX(int ix)
	{
		_ix=ix;
	}
	~Point()
	{
		cout<<"~Point()"<<endl;
	}
friend std::ostream & operator<<(std::ostream &os,const Point &rhs);
private:
	int _ix;
	int _iy;
};
std::ostream & operator<<(std::ostream &os,const Point &rhs)
{
	os<<"("<<rhs._ix
		<<","<<rhs._iy
		<<")";
	return os;
}
int main(void)
{
	int *p=new int(10);
	auto_ptr<int> ap(p);
	cout<<"*p="<<*p<<endl;
	cout<<"*ap="<<*ap<<endl;
	cout<<"ap.get()="<<ap.get()<<endl;
	cout<<"p="<<p<<endl;
	return 0;
}
