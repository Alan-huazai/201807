 ///
 /// @file    for_each.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-05 22:01:59
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
using std::vector;
using std::cout;
using std::endl;
#if 0
void display(int num)
{
	cout<<num<<" ";
}
#endif
int main(void)
{
	vector<int> number{1,2,3,4,5};
	//for_each(number.begin(),number.end(),display);
	//diaplay是一元函数，每个元素都执行display方法
	for_each(number.begin(),number.end(),[](int num){
			cout<<num<<" ";
			});
	
	cout<<endl;
	return 0;
}
