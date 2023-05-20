//menu driven progam with binary and linear search
#include<stdio.h>
int a[50];

void linear_search(int n,int e)
{
    int i;
    int flag=0;
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

void binary_search(int low,int high,int e)
{
    int mid;
    mid=(low+high)/2;
    while(low<=high)
    {
        if(e>a[mid])
        {
            low=mid+1;
        }
        else if(e<a[mid])
        {
            high=mid-1;
            mid=(high+low)/2;
        }
        else
        {
            printf("Element found at %d",mid+1);
            break;
        }
    }
    if (low>high)
    printf("Value not found");
}

int main()
{
    int low,high,mid,n,e;
    int choice;
    printf("Enter size of the array:");
    scanf("%d",&n);

    printf("Enter elements in sorted way:");
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter element to search:");
    scanf("%d",&e);
    low=0;
    high=n-1;
    printf("Enter choice:\n1. Linear search \n2. Binary Search\n");
    scanf("%d",&choice);
    if (choice==1)
    {
        linear_search(n,e);
    }
    else if (choice==2)
    {
        binary_search(low,high,e);
    }
}