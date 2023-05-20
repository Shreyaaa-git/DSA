#include<stdio.h>
#include<stdlib.h>

struct Tree
{
    int data;
    struct Tree *lc;
    struct Tree *rc;
};

void buildtree(struct Tree *ptr)
{
    int ch;
    printf("Enter the value:");
    scanf("%d",&ptr->data);

    ptr->lc=NULL;
    ptr->rc=NULL;

    printf("Do you wanna add Left child of %d(0/1)",ptr->data);
    scanf("%d",&ch);
    if (ch==1)
    {
        struct Tree *new = (struct Tree*)malloc(sizeof(struct Tree));
        ptr->lc = new;
        buildtree(new);
    }

    printf("Do you wanna add Right child of %d(0/1)",ptr->data);
    scanf("%d",&ch);
    if (ch==1)
    {
        struct Tree *new = (struct Tree*)malloc(sizeof(struct Tree));
        ptr->rc = new;
        buildtree(new);
    }
}

struct Tree *stack[30];
int Top=-1;

void push(struct Tree *data)
{
    Top++;
    stack[Top]=data;
}

void pop()
{
    if (Top==-1)
    {
        printf("Stack Underflow");
    }
    else
    {
        printf("%d ",stack[Top]->data);
        Top--;
    }
}

void inorder(struct Tree *root)
{
    struct Tree *ptr;
    ptr=root;
    while (ptr!=NULL || Top!=-1)
    {
        while(ptr!=NULL)
        {
            push(ptr);
            ptr=ptr->lc;
        }
        ptr=stack[Top];
        pop();
        ptr=ptr->rc;
    }
}

int main()
{
    struct Tree *root=(struct Tree *)malloc(sizeof(struct Tree));
    buildtree(root);
    printf("Non recursive inorder traversal:");
    inorder(root);
}