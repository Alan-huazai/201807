 ///
 /// @file    replace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-05 23:19:16
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using std::vector;
using std::cout;
using std::endl;
int main(void)
{
	vector<int> numbers{1,2,3,4,5};
	std::less<int> It;//迭代器
	//std::replace_if(numbers.begin(),numbers.end(),bind2nd(It,3),7);
	std::replace_if(numbers.begin(),numbers.end(),bind1st(It,3),7);
	
	std::ostream_iterator<int> osi(cout," ");
	std::copy(numbers.begin(),numbers.end(),osi);
	return 0;
}
