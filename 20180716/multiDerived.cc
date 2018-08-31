 ///
 /// @file    multiDerived.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-17 14:25:27
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class A
{
public:
	virtual
	void a() {cout<<"A::a()"<<endl;}
	virtual
	void b() {cout<<"A::b()"<<endl;}
	void c() {cout<<"A::c()"<<endl;}

};
class B
{
public:
	virtual
	void a() {cout<<"B::a()"<<endl;}
	virtual
	void b() {cout<<"B::b()"<<endl;}
	void c() {cout<<"B::c()"<<endl;}
	void d() {cout<<"B::d()"<<endl;}
};
class C
:public A
,public B
{
public:
	virtual
	void a(){cout<<"C::a()"<<endl;}
	void c(){cout<<"C::c()"<<endl;}
	void d(){cout<<"C::d()"<<endl;}
};
int test1()
{
	C c;
	//c.b(); error存在二义性
	c.A::b();
	c.B::b();
	return 0;
}

int test2()
{
	C c;
	A *pA=&c;
	pA->a();
	pA->b();
	pA->c();
}
void test3()
{
	C c;
	B *pB=&c;
	pB->a();
	pB->b();
	pB->c();
	pB->d();
}
int main(void)
{
	test3();
	return 0;
}
