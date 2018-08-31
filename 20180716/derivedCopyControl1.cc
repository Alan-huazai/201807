 ///
 /// @file    derivedCopyControl1.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-16 10:07:42
 ///
#include <string.h>
#include <iostream>
using std::cout;
using std::endl;
class Base
{
public:
	Base(const char * data)
	:_data(new char[strlen(data)+1]())
	{
		cout<<"Base(const char *)"<<endl;
		strcpy(_data,data);
	}
	Base(const Base &rhs)
	:_data(new char[strlen(rhs._data]+1)]())
	{
		cout<<"Base(const Base &)"<<endl;
		strcpy(_data,data);
	}
	Base & operator=(const Base & rhs)
	{
		cout<<"Base & operator=(const Base &))"<<endl;
		if(this!=&rhs)
		{
			delete []_data;
			_data=new char[strlen(rhs._data)+1]();
			strcpy(_data,rhs._data);
		}
		return *this;
	}
private:
	char * _data;
};
class Derived
:public Base
{
public:
	Derived(const char * data)
	:Base(data)
	{
		cout<<"Derived(const char *)"<<endl;
	}
	~Derived()
	{
		cout<<"~Derived()"<<endl;
	}

};
