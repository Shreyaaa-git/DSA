#include<stdio.h>

int arr[100];
int Front=-1;
int Rear=-1;

void ENQUEUE(int Maxsize,int Item)
{
    if (Rear==Maxsize)
    {
        printf("Overflow");
    }
    if (Rear==-1 && Front==-1)
    {
        Front++;
        Rear++;
        arr[Rear]=Item;
    }
    else
    {
        Rear++;
        arr[Rear]=Item;
    }
}

void DEQUEUE()
{
    int Value;
    if (Front==-1 && Rear==-1)
    {
        printf("Underflow");
    }
    else if(Front==Rear)
    {
        Value=arr[Front];
        Front=-1;
        Rear=-1;
        printf("The element %d is deleted\n",Value);
    }
    else
    {
        Value=arr[Front];
        Front++;
        printf("The element %d is deleted\n",Value);
    }
}

int PEEK()
{
    if (Front==-1)
    {
        printf("arr empty");
    }
    else
    {
        return (arr[Front]);
    }
}

int DISPLAY()
{
    for(int i=Front;i<=Rear;i++)
    {
        printf("%d\n",arr[i]);
    }
}

int main()
{
    char c='y';
    int choice;
    int p;
    int Front=-1,Rear=-1,Maxsize,Item;
    printf("Enter maxsize of the queue=");
    scanf("%d",&Maxsize);
    while (c='y')
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.Peek\n4.Display\n5.IsEmpty\n6.IsFull\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            printf("Enter element:");
            scanf("%d",&Item);
            ENQUEUE(Maxsize,Item);
        }
        if (choice==2)
        {
            DEQUEUE();
        }
        if (choice==3)
        {
            p=PEEK();
            printf("Peek element=%d\n",p);
        }
        if (choice==4)
        {
            DISPLAY();
        }
        if (choice==5)
        {
            if (Front==-1 && Rear==-1)
            {
                printf("Queue is empty\n");
            }
            else
            {
                printf("Queue is not empty\n");
            }
        }
        if (choice==6)
        {
            if (Front==Maxsize && Rear==Maxsize)
            {
                printf("Queue is full\n");
            }
            else
            {
                printf("Queue is not full\n");
            }
        }
    }
}