 ///
 /// @file    string.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-13 14:48:57
 ///
 
#include <iostream>
#include <string.h>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
class String
{
public:
	String()
	:_pstr(new char [1]())
	{
		cout<<"String()"<<endl;
	}
	String(const char * pstr)
	:_pstr(new char[1]())
	{
		strcpy(_pstr,pstr);
		cout<<"String(const)"<<endl;
	}
	String(const String &rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout<<"String(const String &rhs)"<<endl;
	}
	~String()
	{
		cout<<"~String"<<endl;
		delete []_pstr;
	}
private:
	char * _pstr;
};
int main(void)
{
	vector<String> vec;
	vec.push_back("hello world");
	
	return 0;
}

