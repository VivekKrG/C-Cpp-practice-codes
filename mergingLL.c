#include<stdio.h>

struct node* rev(struct node*);

struct node{
    int val;
    struct node* next;
};

struct node* insert(int);
struct node* trav(struct node*, int);
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

    trav(linked1,1);
    trav(linked2,2);

    linked1=merge(linked1,linked2);
    trav(linked1,1);
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

struct node* trav(struct node* head, int which){
    printf("Entered values in Linked List %d are\n", which);
    struct node* temp=head;
    while(temp){
        printf("%d  ",temp->val);
        temp=temp->next;
    }
    printf("\n");
}

struct node* merge(struct node* h1, struct node* h2){
    int n1=0, n2=0;
    struct node* t1;
    struct node* t2;
    t1=h1;
    t2=h2;

    while(t1!=NULL && t2!=NULL){
        if( (t1->next||t1->next )&&((t1->val) <= (t2->val)) ){
            if( t1->next!=NULL ){
                while( (t1->next)->val <= (t2->val)) {
                    t1=t1->next;
                    if( t1->next==NULL )
                        break;
                }
                struct node* temp=t1;
                t1=t1->next;
                temp->next=h2;
                h2=h1;
                h1=t1;
            }
            printf("Ok");
        }
        //printf("Ok2");

        else if( (t1->next||t1->next ) && ((t2->val) <= (t1->val)) ){
                if( t2->next!=NULL ){
                    while(t2->next->val < t1->val){
                        t2=t2->next;
                        if(t2->next==NULL)
                            break;
                    }
                    struct node* temp=t2;
                    t2=t2->next;
                    temp->next=h1;
                    h1=h2;
                    h2=t2;
                }

        }
    }
    if(h1)
        return h1;
    else
        return h2;
}
