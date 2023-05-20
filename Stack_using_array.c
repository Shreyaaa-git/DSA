#include<stdio.h>

int *PUSH(int STACK[50],int TOP,int MAXSIZE,int VALUE)
{
    if (TOP==MAXSIZE)
    {
        printf("OVERFLOW");
    }
    else
    {
        TOP++;
		STACK[TOP]=VALUE;
    }
    return STACK;
}

int *POP(int STACK[50],int TOP)
{
    int DATA;
    if (TOP=-1)
    {
        printf("UNDERFLOW");
    }
    else
    {
        DATA=STACK[TOP];
        TOP--;
    }
    return STACK;
}

int main()
{
    int a[50]={0};
    int *p;
    int TOP=-1;
    int n;
    int inp;
    int data;
    printf("Enter the size of the array=");
    scanf("%d",&n);

    char c='y';

    while (c=='y'|| c=='Y')
    {
        printf("1.CHECK IF STACK IS EMPTY\n2.DISPLAY THE CONTENTS\n3.PUSH\n4.POP\n");
        scanf("%d",&inp);
        if (inp==1)
        {
            if (TOP==-1)
            printf("STACK is empty");
            else
            printf("STACK is not empty");
        }
        if(inp==2)
        {
            for(int i=0;i<=TOP;i++)
            {
                printf("%d",a[i]);
            }
        }
        if (inp==3)
        {
            printf("Enter the value:");
            scanf("%d",&data);
            p=PUSH(a,TOP,n-1,data);
        }

        if (inp==4)
        {
            p=POP(a,TOP);
        }
        printf("Do you want to continue(y/n):");
        scanf("%c",&c);
        scanf("%c",&c);
    }
    return 0;
}