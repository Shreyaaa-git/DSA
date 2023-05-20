#include <stdio.h>
void main()
{
    int n;
    printf("Enter the no of elements in array:");
    scanf("%d", &n);

    int arr[n];
    printf("Enter elements of array:");
    for ( int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }
    for(int i=0; i<=n; i++)
    {
        for(int j=i+1; j<=n; j++)
        {
            if(arr[j]<arr[i])
            {
                int temp;
                temp=arr[j];
                arr[j]=arr[i];
                arr[i]=temp;
            }
        }
    }

    printf("The sorted array is:");
    for(int i=0; i<n; i++)
    {
      printf("%d ",arr[i]);
    }
}