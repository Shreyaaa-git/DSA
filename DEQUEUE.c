#include<stdio.h>

int que[50];
int front=-1,rear=-1;

void en_front(int size)
{
    if ((front+1==rear) || (rear==-1 && front==size) || ((front==-1) && (rear=0)))
    {
        printf("Overflow");
    }
    else
    {
        front++;
        printf("Enter item:");
        scanf("%d",&que[front]);
    }
}

void en_end(int size)
{
    if ((front+1==rear) || (rear==-1 && front==size) || ((front==-1) && (rear=0)))
    {
        printf("Overflow");
    }
    else
    {
        rear--;
        printf("Enter item:");
        scanf("%d",&que[rear]);
    }
}

void deq_front()
{
    if (rear==-1 && front==-1)
    {
        printf("Underflow");
    }
    else
    {
        front--;
    }
}

void deq_last(int size)
{
    if (rear==-1 && front==-1)
    {
        printf("Underflow");
    }
    else if(rear==size)
    {
        rear=-1;
    }
    else
    {
        rear++;
    }
}

void disp(int size)
{
    int i;
    for(i=front;i!=rear;i=(i+1)%size)
    {
        printf("%d ",que[i]);
    }
    printf("%d ",que[rear]);
}

int main()
{
    int size;
    int choice;
    char c;
    while (c='y')
    {
        printf("1.insert at first\n2.insert at last\n3.delete at first\n4.delete at last\n5.display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            en_front(size);
        }
        if (choice==2)
        {
            en_end(size);
        }
        if (choice==3)
        {
            deq_front();
        }
        if (choice==4)
        {
            deq_last(size);
        }
        if (choice==5)
        {
            disp(size);
        }
    }
}