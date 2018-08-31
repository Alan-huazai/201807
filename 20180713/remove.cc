 ///
 /// @file    remove.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-13 16:43:26
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <utility>
using std::vector;
using std::cout;
using std::endl;

int main(void)
{
	vector<int> numbers{1,2,3,4,5,6,7,8,9,10};
	numbers[2]=numbers[4]=numbers[6]=88;
	auto f=std::remove(numbers.begin(),numbers.end(),88);
	numbers.erase(f,numbers.end());
	copy(numbers.begin(),numbers.end(),std::ostream_itreator<int>(cout," "));
	return 0;
}
