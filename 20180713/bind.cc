 ///
 /// @file    bind.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-13 17:16:25
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::bind;
int func1(int x,int y)
{
	cout<<"func1(int,int)"<<endl;
	return x+y;
}
class Foo
{
	public:
		int fun2(int x,int y)
		{
			cout<<"int Foo::fun2(int,int)"<<endl;
			return x+y;
		}
};
int test1(void)
{
	typedef int (*Function)(int,int);//函数指针
	Function f1=func1;  //注册回调函数
	int a=1,b=2;
//	cout<<"a+b="<<f1(a,b)<<endl;
//	auto f2=bind(func1,a,b);
//	cout<<"a+b="<<f2()<<endl;
	auto f3=bind(func1,a,std::placeholders::_1);
	cout<<"a+b="<<f3(b)<<endl;
	return 0;
}
void test2(void)
{
	Foo f;
	auto fx=bind(&Foo::fun2,f,std::placeholders::_1,std::placeholders::_2);
	cout<<fx(1,2)<<endl;
	auto fx=bind(&Foo::fun2,&f,std::placeholders::_1,std::placeholders::_2);
	cout<<fx(1,2)<<endl;
}
int main()
{
	test2();
	return 0;
}
