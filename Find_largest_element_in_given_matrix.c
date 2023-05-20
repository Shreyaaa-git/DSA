#include <stdio.h>

int main()
{
    int m[100][100],r,c,T[100][100],k=0,count=1,large;
    printf("Enter the number of rows:");
    scanf("%d",&r);
    printf("Enter the number of columns:");
    scanf("%d",&c);
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("Enter element [%d][%d]:",i,j);
            scanf("%d",&m[i][j]);
            if (m[i][j]!=0)
            k++;
        }
    }
    
    printf("The matrix becomes:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }
    
    T[0][0]=r;
    T[0][1]=c;
    T[0][2]=k;
    for(int i=0;i<k+1;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (m[i][j]!=0)
            {
                T[count][0]=i;
                T[count][1]=j;
                T[count][2]=m[i][j];
                count++;
            }
        }
    }
    
    printf("The sparse matrix becomes:\n");
    for (int i=0;i<k+1;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d\t",T[i][j]);
        }
        printf("\n");
    }
    
    count=0;
    
    large=T[count][2];
    for (int i=1;i<k+1;i++)
    {
        if (T[i][2]>large)
        large=T[i][2];
    }
    printf("Largest element is:%d",large);
    

    return 0;
}
