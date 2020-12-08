/*
Two numbers are stored in two Linked List as digit by digits in reverse order.
Write a program to add these numbers.
*/

#include<stdio.h>

typedef struct Node{
                    int data;
                    struct Node* link;
                    }node;

node* num_to_llist(int);
void show_llist(node*);
node* add_nums_in_llist(node*, node*);

void main(){
    //node* llist = (node*)malloc(sizeof(node));
    node* num_as_llist;

    node *head1, *head2;
    head1 = num_to_llist(0);
    show_llist(head1);
    head2 = num_to_llist(996);
    show_llist(head2);

    node *sum;
    sum = add_nums_in_llist(head1, head2);
    show_llist(sum);
}


node* num_to_llist(int number){
    node* head = (node*)malloc(sizeof(node));
    if (number==0){
        head->data = 0;
        head->link = NULL;
        return head;
    }

    node* temp;
    temp = head;
    while(number/10){
        temp->data = number%10;
        number /= 10;
        node* new_node = (node*)malloc(sizeof(node));
        temp->link = new_node;
        temp = new_node;
    }
    temp->data = number;
    temp->link = NULL;

    return head;
}

void show_llist(node* head){
    printf("\n");
    while(head->link){
        printf("%d ->", head->data);
        head = head->link;
    }
    printf("%d", head->data);
}

node* add_nums_in_llist(node* head1, node* head2){
    node *temp, *sum = (node*)malloc(sizeof(node));
    temp = sum;

    int carry = 0;
    while(head1->link && head2->link){
        int added = head1->data + head2->data + carry;
        temp->data = added%10;
        carry = added/10;
        node* new_node = (node*)malloc(sizeof(node));
        temp->link = new_node;
        temp = new_node;
        new_node->link = NULL;

        head1 = head1->link;
        head2 = head2->link;
    }

    node *head;
    head = NULL;
    if(head2->link){
        //head1->link = head2->link;
        head = head2->link;
    }
    else if(head1->link){
        head = head1->link;
    }
    else{
        int added = head1->data + head2->data + carry;
        temp->data = added%10;
        carry = added/10;
        //temp->link = NULL;
    }

    if(head){
        int added = head1->data + head2->data + carry;
        temp->data = added%10;
        carry = added/10;

        while(head && carry){
            node* new_node = (node*)malloc(sizeof(node));
            temp->link = new_node;
            temp = new_node;
            //head1 = head1->link;
            added = head->data+carry;
            temp->data = added%10;
            carry = added/10;
            temp->link = NULL;
            head = head->link;
        }
        if (head){
            temp->link = head;
        }
    }

    if(carry){
            node* new_node = (node*)malloc(sizeof(node));
            temp->link = new_node;
            new_node->data = 1;
            new_node->link = NULL;
    }
    return sum;
}
