 ///
 /// @file    weak_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 23:50:12
 ///
 
#include <iostream>
#include <memory>
using std::weak_ptr;
using std::shared_ptr;
using std::cout;
using std::endl;
struct Foo
{
	void display()const
	{
		cout<<"Foo::display()"<<endl;
	}
};
int main(void)
{
	weak_ptr<Foo> wp;
	{
		shared_ptr<Foo> sp(new Foo);
		cout<<"sp's use_count="<<sp.use_count()<<endl;

		wp=sp;
		cout<<"wp's use_count="<<wp.use_count()<<endl;
//		weak_ptr不能进行直接访问资源
//		cout<<"*wp="<<*wp<<endl;
		//必须提升到share_ptr才能进行访问
		shared_ptr<Foo> sp2=wp.lock();
		if(sp2)
		{
			cout<<"weak_ptr提升成功"<<endl;
			sp2->display();
		}
	}
	cout<<"退出语句块之后，Foo对象的生命周期已经结束"<<endl;
	cout<<"weak_ptr对象还存在，但它知道它所托管的对象是够存活"<<endl;
	shared_ptr<Foo> sp3=wp.lock();
	if(sp3)
	{
		cout<<"weak_ptr提升成功"<<endl;
		sp3->display();
	}
	else
	{
		cout<<"weak_ptr提升失败，Foo对象已经回收了"<<endl;
	}
	return 0;
}
