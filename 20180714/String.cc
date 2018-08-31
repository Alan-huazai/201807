 ///
 /// @file    String.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 14:37:25
 ///
 
#include <iostream>
#include <vector>
#include <string.h>
using std::vector;
using std::cout;
using std::endl;
class String
{
public:	
	String()
	:_pstr(new char[1]())
	{
		cout<<"String()"<<endl;
	}
	String(const char * pstr)
	:_pstr(new char[strlen(pstr)+1]())
	{
		strcpy(_pstr,pstr);
		cout<<"String(const char *pstr)"<<endl;
	}

	String(const String &rhs)
	:_pstr(new char[strlen(rhs._pstr)+1]())
	{
		strcpy(_pstr,rhs._pstr);
		cout<<"String(const String &rhs)"<<endl;
	}
	//移动构造函数
	String(String && rhs)
	:_pstr(rhs._pstr)
	{
		rhs._pstr=NULL;
		cout<<"String(String&& rhs)"<<endl;
	}
	~String()
	{
		delete []_pstr;
		cout<<"~String()"<<endl;
	}

	//移动赋值运算符函数
	String & operator=(String &&rhs)
	{
		cout<<"String & operator=(String&&rhs)"<<endl;
		if(this!=&rhs)
		{
			_pstr=rhs._pstr;
			rhs._pstr=NULL;
		}
		return *this;
	}
friend std::ostream & operator<<(std::ostream &os,const String &rhs);
private:
	char * _pstr;
};
std::ostream & operator<<(std::ostream &os,const String &rhs)
{
	os<<rhs._pstr;
	return os;
}
int main(void)
{
//	vector<String> vec;
	//push_back执行下面语句时，会产生一个临时对象，然后再放入vector中
//	vec.push_back("hello,world");//const String *pstr=String("hello,world"); 创建一个匿名对象
	String s1("hello,world");
	//cout<<"s1="<<s1<<endl;
	s1=String("shenzhen");
	//cout<<"s1="<<s1<<endl;

	//下面的情况是隐式地将s1从左值转换成右值
	//String s2=s1;
	//cout<<"s2="<<s2<<endl;
	//下面的情况是将s1显示地从左值转化成右值
	String s2=std::move(s1);
	//String s2=s1;  //隐式转换s1还是存在
	cout<<"s1="<<s1<<endl;
	cout<<"s2="<<s2<<endl;
	return 0;
}
