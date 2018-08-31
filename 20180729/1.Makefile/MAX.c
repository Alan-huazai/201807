 ///
 /// @file    MAX.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-29 09:01:51
 ///
#include "MAX.h"
int MAX(int arr[],int n	)
{
	int max=arr[0];
	for(int i=0;i<n;++i)
	{
		if(max<arr[i])
		{
			max=arr[i];
		}
	}
	return max;
}
