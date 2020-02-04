/*
*2. Write a program to reverse singly linked list
*/
#include<stdio.h>

struct node* rev(struct node*);

struct node{
    int val;
    struct node* next;
};

void main(){
    int size;
    struct node* head=(struct node*)malloc( sizeof(struct node));
    printf("Enter Number of elements=");
    scanf("%d", &size);
    printf("Now enter elements of linked list one by one\n");

    //Inserting first element
    scanf("%d",&head->val);
    head->next=NULL;

    int count;
    for ( count=1; count<size; count++){
        struct node* temp=head;
        int pos=1;
        while(pos !=count){
            temp=temp->next;
            pos++;
        }
        struct node* nextVal=(struct node*)malloc( sizeof(struct node));
        scanf("%d", &nextVal->val);
        nextVal->next=NULL;
        temp->next=nextVal;
    }

    printf("You have entered following List:\n");
    struct node* temp=head;
    while(temp){
        printf("%d  ",temp->val);
        temp=temp->next;
    }
    printf("\n");

    //Reversing code:-
    printf("Reversed Liked List is:\n");
    temp=rev(head);
    while(temp!=NULL){
        printf("%d  ",temp->val);
        temp=temp->next;
    }

    return 0;
}

struct node* rev( struct node* head){
    struct node* prev=NULL;
    struct node* temp=NULL;

    while(head!=NULL){
        temp = head;
        head=head->next;
        temp->next=prev;
        prev=temp;
    }
    return prev;
}

