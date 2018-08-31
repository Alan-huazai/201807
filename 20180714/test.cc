 ///
 /// @file    test.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 16:40:20
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{
friend std::ostream & operator<<(std::ostream &os,Point &rhs);
public:
	Point(int ix,int iy)
	:_ix(ix)
	, _iy(iy)
	{
		cout<<"Point(int ix,int iy)"<<endl;
	}
private:
	int _ix;
	int _iy;
};
std::ostream & operator<<(std::ostream &os,Point &rhs)
{
	os<<"("<<rhs._ix
		<<","<<rhs._iy
		<<")";
	return os;
}
int main(void)
{
	Point p1(1,2);
	cout<<p1<<endl;
	return 0;
}
