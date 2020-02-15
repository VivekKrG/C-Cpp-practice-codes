/*
*Q4. Write a program to merge two singly linked list in sorted order.
*/
#include<stdio.h>

struct node* rev(struct node*);

struct node{
    int val;
    struct node* next;
};

struct node* insert(int);
struct node* trav(struct node*);
struct node* merge(struct node*, struct node*);

void main(){
    printf("***This program is to merge two linked list in sorted order***\n");

    int size1, size2;

    printf("Enter Number of elements in fist Linked List=");
    scanf("%d", &size1);
    struct node* linked1=insert(size1);

    printf("Enter Number of elements in second Linked List=");
    scanf("%d", &size2);
    struct node* linked2=insert(size2);


    printf("Entered values in Linked List 1 are\n");
    trav(linked1);
    printf("Entered values in Linked List 2 are\n");
    trav(linked2);

    linked1=merge(linked1,linked2);
    printf("Sorted Linked List is:\n");
    trav(linked1);
    return 0;
}

struct node* insert(int size){
    struct node* head=(struct node*)malloc( sizeof(struct node));
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
    return head;
}

struct node* trav(struct node* head){
    struct node* temp=head;
    while(temp){
        printf("%d  ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}
struct node *Head=NULL;
struct node* merge(struct node* h1, struct node* h2){
    int n1=0, n2=0;
    struct node* prev=NULL;
    if( h1->val > h2->val )
    {
      Head=h2;
      h2=h2->next;

    }
    else{
        Head=h1;
        h1=h1->next;
    }
    prev=Head;
    while(h1!=NULL && h2!=NULL){
            if(h1->val > h2->val)
                {
                  prev->next=h2;
                  prev=prev->next;
                  h2=h2->next;

                }
            else{
                prev->next=h1;
                prev=prev->next;
                h1=h1->next;
            }
            if(h1==NULL)
                  prev->next=h2;

            if(h2==NULL)
                  prev->next=h1;
    }
    return Head;
}
