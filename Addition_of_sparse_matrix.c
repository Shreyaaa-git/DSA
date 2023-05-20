#include<stdio.h>
int main()
{
    int m1[50][50],m2[50][50],T1[50][3],T2[50][3];
    int r,c;
    int k1=0,k2=0,count=1;
    int x=1,y=1,z=1;
    int T3[50][3];
    printf("Enter the number of rows of the two matrices:");
    scanf("%d",&r);
    printf("Enter the number of columns of the two matrices:");
    scanf("%d",&c);

    printf("For 1st matrix:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("Enter element [%d][%d]:",i,j);
            scanf("%d",&m1[i][j]);
            if (m1[i][j]!=0)
            k1++;
        }
    }
    
    printf("The matrix becomes:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("%d\t",m1[i][j]);
        }
        printf("\n");
    }

    printf("For 2nd matrix:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("Enter element [%d][%d]:",i,j);
            scanf("%d",&m2[i][j]);
            if (m2[i][j]!=0)
            k2++;
        }
    }
    
    printf("The matrix becomes:\n");
    for (int i=0;i<r;i++)
    {
        for (int j=0;j<c;j++)
        {
            printf("%d\t",m2[i][j]);
        }
        printf("\n");
    }

    T1[0][0]=r;
    T1[0][1]=c;
    T1[0][2]=k1;
    for(int i=0;i<k1+1;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (m1[i][j]!=0)
            {
                T1[count][0]=i;
                T1[count][1]=j;
                T1[count][2]=m1[i][j];
                count++;
            }
        }
    }
    
    printf("The 1st sparse matrix becomes:\n");
    for (int i=0;i<k1+1;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d\t",T1[i][j]);
        }
        printf("\n");
    }

    count=1;

    T2[0][0]=r;
    T2[0][1]=c;
    T2[0][2]=k2;
    for(int i=0;i<k2+1;i++)
    {
        for (int j=0;j<3;j++)
        {
            if (m2[i][j]!=0)
            {
                T2[count][0]=i;
                T2[count][1]=j;
                T2[count][2]=m2[i][j];
                count++;
            }
        }
    }
    
    printf("The 2nd sparse matrix becomes:\n");
    for (int i=0;i<k2+1;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d\t",T2[i][j]);
        }
        printf("\n");
    }

    printf("Addition of the 2 sparse matrix is:\n");
    
    T3[0][0]=r;
    T3[0][1]=c;
    while(x<=k1 && y<=k2)
        {
            if (T1[x][0]<T2[y][0] || T1[x][1]<T2[y][1])
            {
                T3[z][0]=T1[x][0];
                T3[z][1]=T1[x][1];
                T3[z][2]=T1[x][2];
                x++,z++;
            }
            else if (T2[y][0]<T1[x][0] || T2[y][1]<T1[x][1])
            {
                T3[z][0]=T2[y][0];
                T3[z][1]=T2[y][1];
                T3[z][2]=T2[y][2];
                y++,z++;
            }
            else if (T2[x][0]==T1[y][0] && T2[x][1]==T1[y][1])
            {
                T3[z][0]=T2[y][0];
                T3[z][1]=T2[y][1];
                T3[z][2]=T1[x][2]+T2[y][2];
                x++,y++,z++;
            }
        }
    
    while((x<=k1) && (y>k2))
    {
        T3[z][0]=T1[x][0];
        T3[z][1]=T1[x][1];
        T3[z][2]=T1[x][2];
        x++;z++;
    }
    while((x>k1) && (y<=k2))
    {
        T3[z][0]=T2[y][0];
        T3[z][1]=T2[y][1];
        T3[z][2]=T2[y][2];
        y++;z++;
    }
    T3[0][2]=z-1;
    
    for (int i=0;i<z;i++)
    {
        for (int j=0;j<3;j++)
        {
            printf("%d\t",T3[i][j]);
        }
        printf("\n");
    }

    return 0;
}