#include<stdio.h>
#include <stdbool.h>
int wiggleMaxLength(int* nums,int numsSize){
	if(numsSize<2){
		return numsSize;
	}
	int length=1,i;
	bool decrease;
	for(i=1;i<numsSize;i++){
		if(length==1){
			if(nums[i]>nums[i-1]){
				length++;
				decrease=true;
			}
			if(nums[i] <nums[i-1]){
				length++;
				decrease=false;
			}
		}else{
			if(decrease){
				if(nums[i]<nums[i-1]){
					length++;
					decrease=false;
				}
			}else{
				if(nums[i]>nums[i-1]){
					length++;
					decrease=true;
				}
			}
		}
	}
	return length++;
}

int length(int* ar)
{
    return sizeof(ar)/sizeof(ar[0]);
}

int main(int argc,char* argv[]){
	int nums[]={1,7,4,9,2,5};
	printf("摆动序列的长度为%d\n",wiggleMaxLength(nums,6));
	return 0;
}


