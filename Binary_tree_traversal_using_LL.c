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
    printf("Do you want to add left child of %d :", ptr->data);
    scanf("%d",&ch);

    if (ch==1)
    {
        struct tree *new = (struct tree*)malloc(sizeof(struct tree));
        ptr->lc = new;
        buildtree(new);
    }

    printf("Do you want to add right child of %d :", ptr->data);
    scanf("%d",&ch);

    if (ch==1)
    {
        struct tree *new = (struct tree*)malloc(sizeof(struct tree));
        ptr->rc = new;
        buildtree(new);
    }
}

void inorder_display(struct tree *ptr)
{
    
    if(ptr->lc != NULL)
        inorder_display(ptr->lc);
    printf("%d ",ptr->data);
    if(ptr->rc != NULL)
        inorder_display(ptr->rc);
}
void preorder_display(struct tree *ptr)
{
    
    printf("%d ",ptr->data);
    if(ptr->lc != NULL)
    preorder_display(ptr->lc);
    if(ptr->rc != NULL)
    preorder_display(ptr->rc);
}
void postorder_display(struct tree *ptr)
{
    
    if(ptr->lc != NULL)
        postorder_display(ptr->lc);
    if(ptr->rc != NULL)
        postorder_display (ptr->rc);
    printf("%d ",ptr->data);
}

int main()
{
    struct tree *root;
    root = (struct tree*)malloc(sizeof(struct tree));
    buildtree(root);

    printf("\ninorder traversal : ");
    inorder_display(root);
    printf("\npretorder traversal : ");
    preorder_display(root);
    printf("\npostorder traversal : ");
    postorder_display(root);
}