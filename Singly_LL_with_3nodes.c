#include<stdio.h>

struct Node
{
    int data;
    struct Node*next;
};

int main()
{
    struct Node*Head,*ptr;
    struct Node N1,N2,N3;
    Head=&N1;
    N1.data=10;
    N1.next=&N2;
    N2.data=20;
    N2.next=&N3;
    N3.data=30;
    N3.next=NULL;

    ptr=Head;
    while (ptr!=NULL)
    {
        printf("%d ",ptr->data);
        ptr=ptr->next;
    }
}