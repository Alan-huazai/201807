 ///
 /// @file    Derived1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-15 13:42:20
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
:public Base	//public类型的继承称为接口继承
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
int main()
{
	Derived d;
	Derived d2;
	return 0;
}

