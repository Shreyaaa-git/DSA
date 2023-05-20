#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *next;
};
struct node *f;
struct node *r;

void en()
{
    struct node *new;
    new=(struct node*) malloc(sizeof(struct node));
    new->next=NULL;
    printf("Enter item:");
    scanf("%d",&new->info);
    if(f==NULL && r==NULL)
    {
        f=new;
        r=new;
    }
    else
    {
        r->next=new;
        r=new;
    }
}

void deq()
{
    struct node *temp;
    if (f==NULL & r==NULL)
    {
        printf("Underflow");
    }
    
    else
    {
        temp=f;
        f=f->next;
        free(temp);
    }
}

void peek()
{
    if (f==NULL && r==NULL)
    {
        printf("Empty");
    }
    else
    {
        printf("%d",f->info);
    }
}

void disp()
{
    struct node *ptr;
    ptr=f;
    while(ptr!=r)
    {
        printf("%d",ptr->info);
        ptr=ptr->next;
    }
    printf("%d",ptr->info);
}

int main()
{
    struct node *f, *r;
    f=NULL;
    r=NULL;
    int choice;
    char c;
    while (c='y')
    {
        printf("1.ENQUEUE\n2.DEQUEUE\n3.Peek\n4.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            en();
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
    }
}