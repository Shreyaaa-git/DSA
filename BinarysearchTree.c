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

int minsearch(struct Tree *root)
{
    struct Tree *ptr;
    ptr=root;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        while(ptr->lc!=NULL)
        {
            ptr=ptr->lc;
        }
    }
    return(ptr->data);
}

int maxsearch(struct Tree *root)
{
    struct Tree *ptr;
    ptr=root;
    if(root==NULL)
    {
        return 0;
    }
    else
    {
        while(ptr->rc!=NULL)
        {
            ptr=ptr->rc;
        }
    }
    return(ptr->data);
}

int main()
{
    int min,max;
    struct Tree *root=(struct Tree *)malloc(sizeof(struct Tree));
    buildtree(root);
    min=minsearch(root);
    printf("Minsearch:%d\n",min);
    max=maxsearch(root);
    printf("Maxsearch:%d",max);
}