#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *top;

void push()
{
    struct node *new;
    new=(struct node *) malloc(sizeof(struct node));
    printf("Enter data:");
    scanf("%d",&new->data);
    new->next=NULL;
    if (top==NULL)
    {
        top=new;
    }
    else
    {
        new->next=top;
        top=new;
    }
}

void pop()
{
    struct node *temp;
    if (top==NULL)
    {
        printf("Underflow");
    }
    else
    {
        temp=top;
        top=top->next;
        free(temp);
    }
}

void disp()
{
    struct node *ptr;
    ptr=top;
    while(ptr!=NULL)
    {
        printf("%d",ptr->data);
        ptr=ptr->next;
    }
    printf("%d",ptr->data);
}

int main()
{
    top=NULL;
    int choice;
    char c;
    while (c='y')
    {
        printf("1.PUSH\n2.POP\n3.Display\n");
        printf("Enter your choice:");
        scanf("%d",&choice);
        if (choice==1)
        {
            push();
        }
        if (choice==2)
        {
            pop();
        }
        if (choice==3)
        {
            disp();
        }
    printf("Continue?");
    scanf("%c",&c);

    }
}