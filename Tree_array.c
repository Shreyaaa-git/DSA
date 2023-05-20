#include<stdio.h>

void buildtree(int a[],int index,int value)
{
    int ch,data;
    a[index]=value;

    printf("Do you wanna add Left child of %d(0/1)",value);
    scanf("%d",&ch);
    if (ch==1)
    {
        printf("Enter left child:");
        scanf("%d",&data);
        buildtree(a,2*index+1,data);
    }

    printf("Do you wanna add Right child of %d(0/1)",value);
    scanf("%d",&ch);
    if (ch==1)
    {
        printf("Enter right child:");
        scanf("%d",&data);
        buildtree(a,2*index+2,data);
    }
}

int main()
{
    int a[20];
    int value;
    for(int i=0;i<20;i++)
    a[i]=-1;

    printf("Enter value of root node:");
    scanf("%d",&value);
    buildtree(a,0,value);

    for(int i=0;i<20;i++)
    {
        if(a[i]==-1)
        {
            printf("_ ");
        }
        else
        {
            printf("%d ",a[i]);
        }
    }
}