#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *Link;
};


int main (void){
struct Node *Head;
struct Node *New;
struct Node *PTR;
Head=NULL;
New=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the value: ");
scanf("%d",&New->data);
fflush(stdin);
New->Link=NULL;
Head=New;
PTR=Head;
char choice;
printf("Do you want to create another node\n\n(Y/N): ");
scanf("%c",&choice);
fflush(stdin);
while(choice=='Y' || choice=='y') {
New=(struct Node*)malloc(sizeof(struct Node));
printf("Enter the value: ");
scanf("%d",&New->data);
fflush(stdin);
New->Link=NULL;
PTR->Link=New;
PTR=PTR->Link;
printf("Do you want to create another node\n\n(Y/N): ");
scanf("%c",&choice);
fflush(stdin);
}
int count=0;
PTR=Head;
while(PTR!=NULL){
    count++;
    PTR=PTR->Link;
}
printf("The Number of Nodes: %d",count);
int key,flag=0;
printf("\nEnter key: ");
scanf("%d",&key);
PTR=Head;
while(PTR!=NULL){
    if(PTR->data==key)
    flag=1;
    PTR=PTR->Link;
}
if (flag==1)
printf("\nSearch Successfull! ");
else
printf("\nSearch NOT Successfull! ");

return 0;
}