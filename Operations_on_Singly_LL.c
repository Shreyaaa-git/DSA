#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct Node* head = NULL;


void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ptr = head;
    temp->data = x;   
    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
        return;
    }
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->next = NULL;
    return;    
} 


void InsertMid(int x, int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ptr = head;
    temp->data=x;
    for(int i = 1; i < n-1; i++)
    {
        ptr=ptr->next;
    }
    temp->next=ptr->next;
    ptr->next=temp;
}

void InsertBig(int x, int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    temp->data = x;   
    temp->next = head;
    head = temp;
}

void Delete(int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ptr = head;
    if(n == 1)
    {
            head  = ptr->next;
            free(temp);
            return;
    }
    for(int i = 0; i < n-2; i++)
    {
        ptr = ptr->next;
    }
    temp = ptr->next;
    ptr->next = ptr->next->next;
}


void Print()
{
    struct Node* ptr = head;
    while(ptr->next != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
}   


int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    printf("\n");
    int num;
    printf("Enter number of nodes: ");
    scanf("%d", &num);
    for(int i = 0; i < num; i++){
        int n, x;
        printf("Enter data and position: ");
        scanf("%d %d", &x, &n);
        if(n == 1)
        {
            InsertBig(x, n);
            Print();
            printf("\n");
        }
        else{
            InsertMid(x, n);
            Print();
            printf("\n");
        }
    }
    Print();
    printf("\n");
    int del;
    printf("Enter node to delete: ");
    scanf("%d", &del);
    Delete(del);
    Print();
    printf("\n");
    return 0;
}