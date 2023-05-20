#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;
struct Node* tail = NULL;


void Insert(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ptr = head;
    temp->data = x;   
    if(head == NULL)
    {
        head = temp;
        temp->next = NULL;
        temp->prev = NULL;
        return;
    }
    while(ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    temp->prev = ptr;
    ptr->next = temp;
    temp->next = NULL;
    tail = temp;
    return;    
}


void InsertBegin(int x)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ptr = head;
    temp->data = x;   
    temp->prev = NULL;
    head->prev = temp;
    temp->next = head;
    head = temp;
}

void InsertMid(int x, int n)
{
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node*));
    struct Node* ptr = head;
    temp->data = x;
    for(int i = 1; i < n-1; i++){
        ptr=ptr->next;
    }
    ptr->next->prev = temp;
    temp->next = ptr->next;
    temp->prev = ptr;
    ptr->next = temp;
}

void DeleteFirst(){
    struct Node* ptr = head;
    head->next->prev = NULL;
    head = head->next;
    free(ptr);
}

void DeleteMid(int n){
    struct Node* ptr = head;
    for(int i = 1; i < n-1; i++){
        ptr=ptr->next;
    }
    struct Node* temp = ptr->next;
    ptr->next->next->prev = ptr;
    ptr->next = ptr->next->next;
    free(temp);
}


void Print(){
    struct Node* ptr = head;
    while(ptr->next!=NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
    printf("%d ", ptr->data);
    printf("\n");

}

void PrintRev(){
    struct Node* ptr = tail;
    while(ptr->prev!=head){
        printf("%d ", ptr->data);
        ptr = ptr->prev;
    }
    printf("%d ", ptr->data);
    printf("%d ", head->data);
    printf("\n");

}




int main()
{
    Insert(1);
    Insert(2);
    Insert(3);
    Insert(4);

    Print();
    PrintRev();
    printf("\n");


    InsertBegin(7);
    InsertBegin(8);
    InsertBegin(9);

    Print();
    PrintRev();
    printf("\n");


    InsertMid(12, 3);

    Print();
    PrintRev();

    InsertMid(11, 8);

    Print();
    PrintRev();

    InsertMid(10, 4);

    Print();
    PrintRev();
    printf("\n");

    
    DeleteFirst();

    Print();
    PrintRev();
    printf("\n");

    
    DeleteMid(2);

    Print();
    PrintRev();

    DeleteMid(4);

    Print();
    PrintRev();
    
    DeleteMid(6);

    Print();
    PrintRev();
    printf("\n");

    
    



    return 0;
}