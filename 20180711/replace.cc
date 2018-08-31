 ///
 /// @file    replace.cc
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-11 21:07:03
 ///
 
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using std::vector;
using std::cout;
using std::endl;
int main(void)
{
	vector<int> numbers{1,2,3,4,5,6};
	std::less<int> lt;  //lt(lhs,rhs)
	//std::replace_if(numbers.begin(),numbers.end(),bind2nd(lt,3),7);
	std::replace_if(numbers.begin(),numbers.end(),bind1st(lt,3),7);
	std::ostream_iterator<int> osi(cout," ");
	std::copy(numbers.begin(),numbers.end(),osi);
	return 0;
}
