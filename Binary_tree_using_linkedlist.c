#include <stdio.h>
#include <stdlib.h>

struct tree
{
    int data;
    struct tree *lc;
    struct tree *rc;
};

void buildtree(struct tree *ptr)
{
    int ch;
    printf("enter the value : ");
    scanf("%d",&ptr->data);
    ptr->lc = NULL;
    ptr->rc = NULL;
    printf("Do you want to add left child of %d(0/1) :", ptr->data);
    scanf("%d",&ch);

    if (ch==1)
    {
        struct tree *new = (struct tree*)malloc(sizeof(struct tree));
        ptr->lc = new;
        buildtree(new);
    }

    printf("Do you want to add right child of %d(0/1) :", ptr->data);
    scanf("%d",&ch);

    if (ch==1)
    {
        struct tree *new = (struct tree*)malloc(sizeof(struct tree));
        ptr->rc = new;
        buildtree(new);
    }
}

void disp(struct tree *ptr)
{
    if(ptr->lc != NULL)
        disp(ptr->lc);
    printf("%d ",ptr->data);
    if(ptr->rc != NULL)
        disp(ptr->rc);
}

int main()
{
    struct tree *root;
    root = (struct tree*)malloc(sizeof(struct tree));
    buildtree(root);
    disp(root);
}