 ///
 /// @file    virtualFunction3.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-16 20:21:46
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Base
{
public:
	virtual
		void display() const
		{
			cout<<"Base::display()"<<endl;
		}
	void callBase1()
	{
		display();
	}
	void callBase2()
	{
		display();
	}
};
class Child
:public Base
{
public:
	void display()const 
	{
		cout<<"Child::display()"<<endl;
	}
	void callChild1()
	{
		display();
	}
};
int main(void)
{
	Base base;
	Child child;

	//base.callBase1();
	//base.callBase2();

	child.callBase1();
	cout<<endl<<"基类指针指向基类对象"<<endl;
	Base * pbase=&base;
	pbase->callBase1();
	cout<<endl<<"基类指针指向派生类对象"<<endl;
	pbase=&child;
	pbase->callBase1();
	return 0;

}
