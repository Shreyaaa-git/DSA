#include<stdio.h>
#include<stdlib.h>

struct Tree
{
    int data;
    struct Tree *lc,*rc;
};

void buildtree(struct Tree *ptr)
{
    int ch;
    printf("Enter the value:");
    scanf("%d",&ptr->data);

    ptr->lc=NULL;
    ptr->rc=NULL;

    printf("Do you wanna add left child of %d(0/1):",ptr->data);
    scanf("%d",&ch);

    if(ch==1)
    {
        struct Tree *new=(struct Tree *)malloc(sizeof(struct Tree));
        ptr->lc=new;
        buildtree(new);
    }

    printf("Do you wanna add right child of %d(0/1):",ptr->data);
    scanf("%d",&ch);

    if(ch==1)
    {
        struct Tree *new=(struct Tree *)malloc(sizeof(struct Tree));
        ptr->rc=new;
        buildtree(new);
    }
}

void search(struct Tree *root,int key)
{
    struct Tree *ptr;
    ptr=root;
    if (root==NULL)
    {
        printf("Root is null");
    }
    else if(ptr->data==key)
    {
        printf("Key %d is found",ptr->data);
    }
    else if(key>ptr->data)
    {
        search(ptr->rc,key);
    }
    else
    {
        search(ptr->lc,key);
    }
}

int main()
{
    int key;
    struct Tree *root=(struct Tree *)malloc(sizeof(struct Tree));
    buildtree(root);
    printf("Enter key to search:");
    scanf("%d",&key);
    search(root,key);
}