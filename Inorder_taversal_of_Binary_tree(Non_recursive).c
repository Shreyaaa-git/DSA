#include<stdlib.h>
#include<stdio.h>

struct node
{
    int data;
    struct node *lc, *rc;
};

void create(struct node *ptr)
{
    int choice;
    printf("Enter data : ");
    scanf("%d",&ptr->data);
    ptr->lc = NULL;
    ptr->rc = NULL;

    printf("left child of %d?(0/1) : ",ptr->data);
    scanf("%d",&choice);
    if(choice == 1)
    {   
        struct node *new = (struct node*)malloc(sizeof(struct node));
        ptr->lc = new;  
        create(new);
    }
    printf("right child of %d?(0/1) : ",ptr->data);
    scanf("%d",&choice);
    if(choice == 1)
    { 
        struct node *new = (struct node*)malloc(sizeof(struct node));
        ptr->rc = new;
        create(new);
    }
    
}
struct node *stack[100];
int top = -1;
void push(struct node *data)
{
    top++;
    stack[top] = data;
}
void pop()
{
    if(top == -1)
        printf("\nstack underflow!");
    else
    {
        printf("%d ",stack[top]->data);
        top--;
    } 
}

void inorder(struct node *root)
{

    struct node *ptr;
    ptr = root;
    
    while(ptr != NULL || top != -1)
    {
        while(ptr != NULL)
        {
            push(ptr);
            ptr = ptr->lc;
        }
        ptr = stack[top];
        pop();
        ptr = ptr->rc;
    }                                                          
}

int main()
{
    struct node *root = (struct node *)malloc(sizeof(struct node));
    create(root);
    printf("non recursive inorder traversal : ");
    inorder(root);

}