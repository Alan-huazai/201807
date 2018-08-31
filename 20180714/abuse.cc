 ///
 /// @file    abuse.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-15 00:19:48
 ///
 
#include <iostream>
#include <memory>
using std::cout;
using std::endl;
using std::shared_ptr;
class Point
:public std::enable_shared_from_this<Point>
{
public:
	Point(int ix=0,int iy=0)
	:_ix(ix)
	 ,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
	shared_ptr<Point> add(Point *pt)
	{
		_ix+=pt->_ix;
		_iy+=pt->_iy;
		return shared_from_this();
	}
	~Point()
	{
		cout<<"~Point()"<<endl;
	}
private:
	int _ix;
	int _iy;
};
void test1()
{
	Point *pt=new Point(1,2);
	shared_ptr<Point> sp(pt);
	shared_ptr<Point> sp2(pt);
}
void test2()
{
	shared_ptr<Point> sp(new Point(1,2));
	shared_ptr<Point> sp2(new Point(3,4));
	shared_ptr<Point> sp3(sp->add(sp2.get()));
}
int main()
{
	test1();
	return 0;
}
