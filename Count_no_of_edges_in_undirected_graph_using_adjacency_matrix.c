/*WAP to input one undirected graph and display the number of edges using adjacency matrix*/

#include<stdio.h>

int main()
{
    int n,count=0;
    int a[15][15];
    printf("Enter number of vertices:");
    scanf("%d",&n);

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("Does %d and %d has an edge(0/1):",i,j);
            scanf("%d",&a[i][j]);
        }
    }

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            printf("%d ",a[i][j]);
            if (a[i][j]==1)
            count++;
        }
        printf("\n");
    }

    printf("Total number of edges in the graph is %d",count/2);
}