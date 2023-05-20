#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* ptr){
    while(ptr != NULL){
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

struct Node* insertbegin(struct Node* HEAD){
    int new;
    printf ("Enter the element to insert in the begining: ");
    scanf ("%d", &new);
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    ptr->next = HEAD;
    ptr->data = new;
    return ptr;
}
struct Node* insertAtEnd(struct Node* HEAD){
    int new;
    printf("Enter the element to insert at the end: ");
    scanf ("%d", &new);
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = HEAD;
    while (p->next!=NULL)
    {
        p = p->next;
    }
    ptr->data = new;
    p->next = ptr;
    ptr->next = NULL;
    return HEAD;
}
struct Node* insertAtIndex(struct Node* HEAD){
    int index, new;
    printf ("Enter the element to insert: ");
    scanf ("%d", &new);
    printf ("Enter in which Index: ");
    scanf ("%d", &index);
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node* p = HEAD;
    int i = 0;
    while (i != index-1)
    {
        p = p->next;
        i++;
    }
    ptr->data = new;
    ptr->next = p->next;
    p->next = ptr;
}

int main()
{
    struct Node *HEAD;
    struct Node *NEW;
    struct Node *PTR;
    HEAD = NULL;
    int choice;
    while (choice)
    {
        NEW = (struct Node *)malloc(sizeof(struct Node));
        printf("Enter Data: ");
        scanf("%d", &NEW->data);
        NEW->next = 0;
        if (HEAD == 0)
        {
            HEAD = PTR = NEW;
        }
        else
        {
            PTR->next = NEW;
            PTR = NEW;
        }
        printf("Do you want to continue (0/1)?\n");
        scanf("%d", &choice);
    }
    printf("Printing the List : \n");
    display(HEAD);
    printf("\n");

    
    printf ("1. Insert in the beginning\n");
    printf ("2. Insert at the end\n");
    printf ("3. Insert at a specific index\n");
    printf ("\nEnter your choice: ");
    scanf ("%d", &choice);

    switch (choice)
    {
    case 1:
        HEAD = insertbegin(HEAD);
        break;
    case 2:
        HEAD = insertAtEnd(HEAD);
        break;
    case 3:
        HEAD = insertAtIndex(HEAD);
        break;    
    default:
        break;
    }
    
    printf("Printing the List : \n");
    display(HEAD);
}