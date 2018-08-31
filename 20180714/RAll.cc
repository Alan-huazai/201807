 ///
 /// @file    RAll.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 18:04:35
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{
public:
	Point(int ix,int iy)
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
template <typename T>
class RAII
{
public:
	RAII(T * p)
	:_p(p)
	{}
	T * get()
	{
		return _p;
	}
	T * operator->()
	{
		return _p;
	}
	T & operator*()
	{
		return *_p;
	}
	~RAII()
	{
		if(_p)
			delete _p;
	}
private:
	T * _p;
};
int main()
{
	RAII<Point> pPoint(new Point(1,2));
	pPoint->setX(10);
	cout<<*pPoint<<endl;
	return 0;
}
