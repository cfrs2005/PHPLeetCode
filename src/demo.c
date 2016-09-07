#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* reverseString(char* s)
{
    int len = strlen(s);
    int i = 0;
    char* ret = (char *)malloc(strlen(s) + 1);

    while (len)
    {
        ret[i++] = s[--len];
    }
    ret[i] = '\0';

    return ret;
}

int main(void)
{
    char ab[]="abcdefg";
    printf("%s : %s\n", "hello", reverseString(ab));

    return 0;
}
