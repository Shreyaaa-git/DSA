#include<stdio.h>

void buildtree(int t[],int index,int value)
{
	int ch;
	int data;
	
	t[index]=value;
	printf("Do you have left child of %d (0/1): ",value);
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Enter the left child: ");
		scanf("%d",&data);
		buildtree(t,2*index+1,data);
	}
	printf("Do you have right child of %d (0/1): ",value);
	scanf("%d",&ch);
	if(ch==1)
	{
		printf("Enter the right child: ");
		scanf("%d",&data);
		buildtree(t,2*index+2,data);	
	}
	
}
int main()
{
	int t[20];
	int index,value;
	
	for(int i=0;i<20;i++)
	t[i]=-1;
	
	printf("21051935-Shreya Chakraborty\n");
	printf("Enter the Root Node: ");
	scanf("%d",&value);
	buildtree(t,0,value);
	for(int i=0;i<20;i++)
	{
		if(t[i]==-1)
		printf("_ ");
		else
		printf("%d ",t[i]);
	}
	
	return 0;
}