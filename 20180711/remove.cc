 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-11 21:25:13
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <unistd.h>
using std::vector;
using std::cout;
using std::endl;
int test1(void)
{
	vector<int> numbers{1,3,4,5,7,8,9,5,5,2};
	numbers[2]=numbers[4]=numbers[6]=88;
	auto f=std::remove(numbers.begin(),numbers.end(),88);
	numbers.erase(f,numbers.end());
	copy(numbers.begin(),numbers.end(),std::ostream_iterator<int>(cout," "));
	return 0;
}
void test2(void)
{
	vector<int> numbers;
	numbers.push_back(1);
	bool flag=true;
	for(auto it=numbers.begin();it!=numbers.end();++it)
	{
		cout<<*it<<endl;
		cout<<"numbers="<<numbers.size()<<endl;
		cout<<"capacity="<<numbers.capacity()<<endl;
		sleep(1);
		if(flag)
		{
			numbers.push_back(2);
			flag=false;
		}
	}
}

int main(void)
{
	test2();
	return 0;
}
