 ///
 /// @file    Derived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-16 10:03:02
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
public:
	Base()
	{
		cout<<"Base()"<<endl;
	}
private:
	int _ib;
};
class Derived
:public Base
{
public:
	Derived()
	{
		cout<<"Derived()"<<endl;
	}
	Derived(int id)
	:_id(id)
	{
		cout<<"Derived(int)"<<endl;
	}
private:
	int _id;
};
int main(void)
{
	Derived d;
	return 0;
}
