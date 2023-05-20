//Insertion sort

#include<stdio.h>

int main()
{
    int a[5];
    int temp,j;
    printf("Enter 5 elements of the array:");

    for(int i=0;i<5;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(int i=0;i<5;i++)
    {
        temp=a[i];
        j=i-1;
        while(j>=0 && a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
    for (int i=0;i<5;i++)
    {
        printf("%d ",a[i]);
    }
}