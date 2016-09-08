#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <assert.h>

bool containsDuplicate(int* nums, int numsSize)
{
    int arr[numsSize];
    int i;
    //很奇怪的地方 不知道为什么 用numsSize就过不了最终的提交
    //看了 memset源码 并没有看出什么鬼 打印的东西并不是我想要的
    memset(arr, 0, numsSize);
    for (i = 0; i < numsSize; i++)
    {
	    printf("init num is %d\n",arr[i]);
        if (arr[nums[i]] == 1)
            return true;
        arr[nums[i]] = 1;
    }
    return false;
}

int main(void)
{
    int arr1[] = {3, 3};
    int arr2[] = {};
    int arr3[] = {0};
    int arr4[] = {1,2,3,14,1};
    assert(containsDuplicate(arr1, 20) == true);
    assert(containsDuplicate(arr2, 0) == false);
    assert(containsDuplicate(arr3, 1) == false);
    printf("result is %d\n",containsDuplicate(arr4,5));
    printf("All passed\n");

    return 0;
}
