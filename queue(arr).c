#include<stdio.h>

int queue[100];
int front=-1;
int rear=-1;

void en(int maxsize)
{
    int item;
    if (rear>=maxsize)
    {
        printf("Overflow");
    }
    else if(front==-1 && rear==-1)
    {
        printf("Enter element:");
        scanf("%d",&item);
        front++;
        rear++;
        queue[rear]=item;
    }
    else
    {
        printf("Enter element:");
        scanf("%d",&item);
        rear++;
        queue[rear]=item;
    }
}

void deq()
{
    if ((front==-1) && (rear=-1))
    {
        printf("Underflow");
    }

    else if(front==rear)
    {
        front=-1;
        rear=-1;
    }
    else
    {
        front++;
    }
}

void peek()
{
    if(front=-1)
    {
        printf("Empty");
    }
    else
    {
        printf("%d",queue[front]);
    }
}

void disp()
{
    for(int i=front; i<rear; i++)
    {
        printf("%d ",queue[i]);
    }
}

void isempty()
{
    if (front==-1 && rear==-1)
    {
        printf("Empty");
    }
}

void isfull(int maxsize)
{
    if (rear==maxsize)
    {
        printf("Full");
    }
}
int main()
{
    int maxsize,item,choice;
    char c;
    printf("Maxsize=");
    scanf("%d",&maxsize);
    while (c='y')
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.Peek\n4.Display\n5.IsEmpty\n6.IsFull\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            en(maxsize);
        }
        if (choice==2)
        {
            deq();
        }
        if (choice==3)
        {
            peek();
        }
        if (choice==4)
        {
            disp();
        }
        if (choice==5)
        {
            isempty();
        }
        if (choice==6)
        {
            isfull(maxsize);
        }
    }
}
