#include <stdlib.h>
#include <stdio.h>
#define MAX 50

int pop(int t, int ar[])
{
    int a;
    if(t==-1)
    {
        printf("Stack Underflow\n");
        exit(1);
    }
    else
    {
        a= ar[t];
        t--;
    }
    return a;
}

void push(int x, int t, int a[])
{
    if(t==MAX-1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        t++;
        a[t]=x;
    }
}

void bin(int num)
{
    int stack[MAX], top=-1,r;
    while(num != 0)
    {
        r = num%2;
        push(r,top, stack);
        num = num/2;
        top++;
    }
    while(top!=-1)
    {
        printf("%d", pop(top, stack));
        top--;
    }
}



int main()
{
    printf("Enter a number : ");
    int n;
    scanf("%d",&n);
    printf("Binary : ");
    bin(n);
    

    return 0;
}