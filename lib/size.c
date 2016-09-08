#include <stdio.h>
#include <stdlib.h>

#define GET_ARRAY_LEN(array,len){len = (sizeof(array) / sizeof(array[0]));}
int main(int argc,char* argv[])
{
	char a[] = {9,8,76,31,23,45,5};
	int len;
	GET_ARRAY_LEN(a,len)
	printf("%d\n",len);
	return 0;
}
