#include<stdio.h>

int que[50];
int front=-1,rear=-1;

void en(int size)
{
    if (front==0 && rear==size-1)
    {
        printf("Overflow");
    }
    else if(front==rear+1)
    {
        printf("Overflow");
    }
    else if((front==-1) && (rear=-1))
    {
        printf("Enter item:");
        front=0;
        rear=0;
        scanf("%d",&que[rear]);
    }
    else
    {
        printf("Enter item:");
        rear=((rear+1)%size);
        scanf("%d",&que[rear]);
    }
}

void deq(int size)
{
    if (front==-1 && rear==-1)
    {
        printf("Underflow");
    }
    else
    {
        front=((front+1)%size);
    }
}

void disp(int size)
{
    int i;
    for(i=front;i!=rear;i=(i+1)%size)
    {
        printf("%d ",que[i]);
    }
    printf("%d ",que[i]);
}

int main()
{
    int size;
    int choice;
    char c;
    while (c='y')
    {
        printf("1.insert\n2.delete\n3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            en(size);
        }
        if (choice==2)
        {
            deq(size);
        }
        if (choice==3)
        {
            disp(size);
        }
    }
}