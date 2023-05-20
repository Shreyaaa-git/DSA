#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *lc, *rc;
};
void create(struct node *ptr)
{
    int choice;
    printf("data : ");
    scanf("%d",&ptr->data);
    ptr->lc = NULL;
    ptr->rc = NULL;

    printf("left child of %d? : ",ptr->data);
    scanf("%d",&choice);
    if(choice == 1)
    {   
        struct node *new = (struct node*)malloc(sizeof(struct node));
        ptr->lc = new;  
        create(new);
    }
    printf("right child of %d? : ",ptr->data);
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
        top--;
    } 
}
void postorder(struct node *root)
{
    struct node *ptr = root;
       
    if(ptr->rc != NULL)
        push(ptr->rc);
    push(ptr);
    ptr = ptr->lc;

    while(top != -1)
    {    
        while(ptr != NULL) 
        {
            if(ptr->rc != NULL)
                push(ptr->rc);
            push(ptr);
            ptr = ptr->lc;
        }
        ptr = stack[top];
        pop();
        if(ptr->rc != NULL && ptr->rc == stack[top])
        {
            pop();
            push(ptr);
            ptr = ptr->rc;
        }
        else
        {   
            printf("%d ",ptr->data);
            ptr = NULL;  
        }
    }                                             
}

int main()
{
    struct node *root = (struct node*)malloc(sizeof(struct node));
    create(root);
    printf("non recursive\n");
    postorder(root);
}