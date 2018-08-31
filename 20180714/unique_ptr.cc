 ///
 /// @file    unique_ptr.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-14 18:42:25
 ///
 
#include <iostream>
#include <memory>
#include <vector>
using std::vector;
using std::unique_ptr;
using std::cout;
using std::endl;
unique_ptr<int> getValue()
{
	unique_ptr<int> up(new int(66));
	return up;
}

int main(void)
{
	unique_ptr<int> up(new int(10));
	cout<<"*up="<<*up<<endl;
	cout<<"up.get()="<<up.get()<<endl;
	
	cout<<"-------------"<<endl;
	//unique_ptr是一个移动语义，定义了移动语义函数
	//unique_ptr不能进行复制，getValue的返回值是一个右值
	up=getValue();
	cout<<"*up="<<*up<<endl;
	cout<<"up.get()="<<up.get()<<endl;

	vector<unique_ptr<int>> vec;
	vec.push_back(std::move(up));
	return 0;
}
