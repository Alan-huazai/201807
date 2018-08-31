 ///
 /// @file    shared_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 23:10:53
 ///
 
#include <iostream>
#include <memory>
using std::shared_ptr;
using std::cout;
using std::endl;
int main()
{
	shared_ptr<int> sp(new int(10));
	cout<<"*sp="<<*sp<<endl;
	cout<<"sp.get()="<<sp.get()<<endl;
	cout<<"sp's use_count="<<sp.use_count()<<endl;
	//共享性智能指针是通过引用计数来实现的
	shared_ptr<int> sp2(sp);
	cout<<"*sp2="<<*sp2<<endl;
	cout<<"sp2.get()="<<sp2.get()<<endl;
	cout<<"sp2's use_count="<<sp2.use_count()<<endl;
	cout<<"*sp="<<*sp<<endl;
	cout<<"sp.get()="<<sp.get()<<endl;
	cout<<"sp's use_count="<<sp.use_count()<<endl;
	return 0;
}
