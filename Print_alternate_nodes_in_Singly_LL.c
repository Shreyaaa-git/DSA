#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node * next;
};

int main()
{
    char s;
    struct Node *Head,*New,*ptr;
    Head=NULL;
    New=(struct Node*)malloc(sizeof(struct Node));
    printf("Enter the data:");
    scanf("%d",&New->data);
    New->next=NULL;
    Head=New;
    ptr=Head;
    printf("Do you want to add a node(Y/N)");
    scanf("%c",&s);
    scanf("%c",&s);
    while (s=='Y' || s=='y')
    {
        New=(struct Node*)malloc(sizeof(struct Node));
        printf("Enter the data:");
        scanf("%d",&New->data);
        New->next=NULL;
        ptr->next=New;
        ptr=ptr->next;
        printf("Do you want to add a node(Y/N)");
        scanf("%c",&s);
        scanf("%c",&s);
    }
    ptr=Head;
    printf("Output data:\n");
    while (ptr!=NULL)
    {
        printf("%d ",(ptr->data));
        ptr=(ptr->next)->next;
    }
    return 0;
}