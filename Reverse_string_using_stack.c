//Reversing a string using stack
#include<stdio.h>
#include<string.h>

int top=-1;
char str1[20];

void push(char c)
{
    top++;
    str1[top] = c;
}

void pop()
{
    printf("%c",str1[top]);
    top--;
}

int main()
{
    printf("Enter string:");
    scanf("%s",&str1);
    int i = 0;
    while(str1[i] != 0)
    {
        push(str1[i]);
        i++;
    }

    while(top != -1)
    {
        pop();
    }
}