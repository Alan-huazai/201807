 ///
 /// @file    deleter.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-15 00:09:15
 ///
#include <stdio.h> 
#include <iostream>
#include <string>
#include <memory>
using std::shared_ptr;
using std::unique_ptr;
using std::cout;
using std::endl;
using std::string;
struct Fpcloser
{
	void operator()(FILE * fp)
	{
		if(fp)
		{
			fclose(fp);
			cout<<">fclose(f)"<<endl;
		}
	}
};
int test0()
{
	shared_ptr<FILE> sp(fopen("test.txt","w"),Fpcloser());
	string s1("hello,world");
	fwrite(s1.c_str(),s1.size(),1,sp.get());
	return 0;
}
int test1()
{
	unique_ptr<FILE,Fpcloser> up(fopen("test.txt","w+"));
	string s1("hello,world");
	fwrite(s1.c_str(),s1.size(),1,up.get());
}
int main()
{
	test0();
	return 0;
}
