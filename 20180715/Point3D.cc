 ///
 /// @file    Point3D.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-15 08:17:53
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
	void print()
	{
		cout<<"("<<_ix
			<<","<<_iy
			<<")"<<endl;
	}
	int getX()
	{
		return _ix;
	}
private:
	int _ix;
protected:
	int _iy;
};
class Point3D
:public Point
{
public:
	Point3D(int ix,int iy,int iz)
	:Point(ix,iy)
	 ,_iz(iz)
	{
		cout<<"Point3D(int,int,int)"<<endl;
	}
	void print()
	{
		cout<<"("<<getX()
			<<","<<_iy
			<<","<<_iz
			<<")"<<endl;
	}
private:
	int _iz;
};
int main(void)
{
	Point3D p(1,2,3);
	p.print();//基类的函数被隐藏
	p.Point::print();
	return 0;
}
