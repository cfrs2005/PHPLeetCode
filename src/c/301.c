#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void traverse(char* s, int len, int start, int left, int right, int pair, char* stack, int top, char*** arr, int *returnSize)
{
    if(start == len)
    {
        if(!left && !right && !pair)
        {
            int size = top+1;
            char *t = (char*)malloc(sizeof(char)*(size+1));
            for(int i = 0; i < size; i++)
                t[i] = stack[i];
            t[size] = '\0';
            int i = 0;
            while(i < *returnSize) //remove duplicates;
            {
                if(!strcmp(t, (*arr)[i]))
                    break;
                i++;
            }
            if(i == *returnSize) //add a bran-new string;
            {
                *returnSize += 1;
                *arr = (char**)realloc(*arr, sizeof(char*)*(*returnSize));
                (*arr)[*returnSize-1] = t;
            }
        }
        return ;
    }
    char c = s[start];
    if(c == '(')
    {
        if(left) //try to remove it;
            traverse(s, len, start+1, left-1, right, pair, stack, top, arr, returnSize);
        stack[top+1] = c; //try to add it as a pair;
        traverse(s, len, start+1, left, right, pair+1, stack, top+1, arr, returnSize);
    }
    else if(c == ')')
    {
        if(right) //try to remove it;
            traverse(s, len, start+1, left, right-1, pair, stack, top, arr, returnSize);
        if(pair) //try to use it as the other half of a pair;
        {
            stack[top+1] = c;
            traverse(s, len, start+1, left, right, pair-1, stack, top+1, arr, returnSize);
        }
    }
    else //just collect since it's not brackets;
    {
        stack[top+1] = c;
        traverse(s, len, start+1, left, right, pair, stack, top+1, arr, returnSize);
    }
}

//AC - 0ms;
char** removeInvalidParentheses(char* s, int* returnSize)
{
    char** arr = (char**)malloc(sizeof(char*));
    *returnSize = 0;
    int left=0, right=0;
    for(int i = 0; s[i]; i++) //find out how many opening and closing brackets should be removed;
    {
        if(s[i] == '(') left++;
        else if(s[i] == ')')
        {
            if(left) left--;
            else right++;
        }
    }
    int len = strlen(s);
    char *stack = (char*)malloc(sizeof(char)*len);
    int top = -1;
    traverse(s, len, 0, left, right, 0, stack, top, &arr, returnSize);
    // printf("%s",arr);
    return arr;
}



int main(){

	char test[]="()())()";
	int* i;
	char* a;
	printf("%s\n",removeInvalidParentheses(test,i));
	// for(i=0;i<sizeof(a)/sizeof(a[0]);i++){
   		// printf("%d  ",a[i]);
   // }

	return 0;

}

