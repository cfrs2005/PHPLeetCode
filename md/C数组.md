## C语言中获取数组长度 

C、C++中没有提供 直接获取数组长度的函数，对于存放字符串的字符数组提供了一个strlen函数获取长度，那么对于其他类型的数组如何获取他们的长度呢？其中一种方法是使 用

```
sizeof(array) / sizeof(array[0])
```

### 在C语言中习惯上在 使用时都把它定义成一个宏，比如

```
#define GET_ARRAY_LEN(array,len) {len = (sizeof(array) / sizeof(array[0]));}
```


### 实例:

```
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
```