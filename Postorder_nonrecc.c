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

void postorder(struct Tree *root)
{
    struct Tree *ptr;
    ptr=root;
    if(ptr->rc != NULL)
        push(ptr->rc);
    push(ptr);
    ptr = ptr->lc;

    while(Top != -1)
    {    
        while(ptr != NULL) 
        {
            if(ptr->rc != NULL)
                push(ptr->rc);
            push(ptr);
            ptr = ptr->lc;
        }
        ptr = stack[Top];
        pop();
        if(ptr->rc != NULL && ptr->rc == stack[Top])
        {
            pop();
            push(ptr);
            ptr = ptr->rc;
        }
        else
        {   
            printf("%d ",ptr->data);
            ptr = NULL;
            while(ptr!=NULL || Top!=-1)
            {
                while(ptr!=NULL)
                {
                    if (ptr->rc!=NULL)
                    {
                        push(ptr->rc);
                    }
                    push(ptr);
                    ptr=ptr->lc;
                    pop();
                    if(ptr->rc!=NULL)
                    {
                        pop();
                        push(ptr);
                        ptr=ptr->rc;
                    }
                    else
                    {
                        printf("");
                    }
                }
            }
        }
    }
}

int main()
{
    struct Tree *root=(struct Tree*) malloc(sizeof(struct Tree));
    buildtree(root);
    printf("Post order without reccursion:");
    postorder(root);
}