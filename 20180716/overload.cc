 ///
 /// @file    overload.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-17 08:02:57
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
protected:
	int m_i;
public:
	int fun(int i)
	{
		return i;
	}
};
class Derived
:public Base
{
public:
	int m_i;
	int func()
	{
		m_i=9;
		Base::m_i=22;
		return m_i;
	}
};
int main(void)
{
	Derived d;
	d.func();
}
