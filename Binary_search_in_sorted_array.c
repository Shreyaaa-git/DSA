#include<stdio.h>

int main()
{
    int a[50],low,high,mid,n,e;

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