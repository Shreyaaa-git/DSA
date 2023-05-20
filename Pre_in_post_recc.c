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

void displayin(struct Tree *ptr)
{
    if(ptr->lc!=NULL)
    {
        display(ptr->lc);
    }
    printf("%d ",ptr->data);
    if(ptr->rc!=NULL)
    {
        display(ptr->rc);
    }
}

void displaypre(struct Tree *ptr)
{
    printf("%d ",ptr->data);
    if(ptr->lc!=NULL)
    {
        display(ptr->lc);
    }

    if(ptr->rc!=NULL)
    {
        display(ptr->rc);
    }
}

void displaypost(struct Tree *ptr)
{
    if(ptr->lc!=NULL)
    {
        display(ptr->lc);
    }

    if(ptr->rc!=NULL)
    {
        display(ptr->rc);
    }
    printf("%d ",ptr->data);
}

int main()
{
    struct Tree *root;
    root=(struct Tree *) malloc(sizeof(struct Tree));
    buildtree(root);
    printf("Inorder:");
    displayin(root);
    printf("Preorder:");
    displaypre(root);
    printf("Postorder:");
    displaypost(root);
}