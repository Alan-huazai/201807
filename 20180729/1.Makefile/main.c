 ///
 /// @file    main.c
 /// @author  lemon(haohb13@gmail.com)
 /// @date    2018-07-29 09:51:57
 ///
#include "MIN.h"
#include "MAX.h"
#include <stdio.h>
int main()
{
	int arr[]={1,2,3,4,5};
	int max=MAX(arr,5);
	int min=MIN(arr,5);
	printf("max=%d\n",max);
	printf("min=%d\n",min);
	return 0;
}
