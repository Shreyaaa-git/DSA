/*WAP to sort an unsorted array using insertion sort*/

#include<stdio.h>

int main()
{
    int arr[5];
    int temp,j;
    printf("Enter 5 elements:");
    for (int i=0;i<5;i++)
    {
        scanf("%d",&arr[i]);
    }
    for (int i=0;i<5;i++)
    {
        temp=arr[i];
        j=i-1;

        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    for (int i=0;i<5;i++)
    {
        printf("%d ",arr[i]);
    }
}