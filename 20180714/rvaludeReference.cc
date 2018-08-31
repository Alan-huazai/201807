 ///
 /// @file    rvaludeReference.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 20:10:21
 ///
 
#include <iostream>
using std::cout;
using std::endl;
int main(void)
{
	int &&m=1;
	int a=2;
	cout<<"&m="<<&m<<endl;
	cout<<"&a="<<&a<<endl;
	return 0;
}
