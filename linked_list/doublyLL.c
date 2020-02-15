/*
* Q3. Write a program to implement a doubly linked list.
*/
#include<stdio.h>
struct node{
    int data;
    struct node* prev;
    struct node* next;
};

struct node* insert(struct node**, int);
struct node* travRt(struct node*);
struct node* travLt(struct node*);

void main(){
    int num;
    struct node* head=NULL;
    printf("***This program is to implement Doubly Liked List***\n");
    printf("Enter number of elements to insert\n");
    scanf("%d",&num);
    printf("Enter elements one by one for Doubly Liked List\n");
    insert(&head, num);

    travRt(head);
    travLt(head);
}

struct node* insert(struct node** headAd, int num){
    int i=0;

    struct node* nw=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&nw->data);
    nw->prev=NULL;
    nw->next=NULL;
    *headAd=nw;

    for(i=0; i<num-1; i++){
        struct node* temp=*headAd;
        while(temp->next){
            temp=temp->next;
        }
        struct node* nw=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&nw->data);
        nw->prev=temp;
        nw->next=NULL;
        temp->next=nw;
    }
}

struct node* travRt(struct node* head){
    printf("\nTraversing of data in Right direction\n");
    while(head){
        printf("%d  ",head->data);
        head=head->next;
    }
}

struct node* travLt(struct node* head){
    printf("\nTraversing of data in Left direction\n");
    while(head->next){
        head=head->next;
    }
    while(head){
        printf("%d  ",head->data);
        head=head->prev;
    }
}
