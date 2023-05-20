#include<stdio.h>

int main()
{
    int a[50],n,e,i;
    int flag=0;
    printf("Enter number of elements in the array=");
    scanf("%d",&n);
    printf("Enter the elements:");
    for (i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to search:");
    scanf("%d",&e);
    for (i=0;i<n;i++)
    {
        if (e==a[i])
        {
            flag=1;
            break;
        }
    }
    if (flag==1)
    {
        printf("Element found at %d",i+1);
    }
    else
    {
        printf("Element not found");
    }
}