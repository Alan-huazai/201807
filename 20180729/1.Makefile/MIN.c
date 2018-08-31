 ///
 /// @file    MIN.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-29 09:07:29
 ///
#include "MIN.h"
int MIN(int arr[],int n)
{
	int min=arr[0];
	for(int i=0;i<n;++i)
	{
		if(min>arr[i])
		{
			min=arr[i];
		}
	}
	return min;
}
