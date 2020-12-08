/*
Given two non-empty Linked List representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit.
Add two numbers and return it as a Linked List.
Numbers do not contain leading 0, except the number 0 itself.
Eg1- 
Number1 = 124
Nu,ber2 = 457
Number1 stored in Linked List as: 4 -> 2 -> 1
Number2 stored in Linked List as: 7 -> 5 -> 7

Sum(in Linked List) return as   : 1 -> 8 -> 8

Eg2:
Num1(1)   : 1
Num2(999) : 9->9->9
Sum(1000) : 0->0->0->1
*/

#include<stdio.h>

typedef struct Node{
                    int data;
                    struct Node* link;
                    }node;

// Function to store integer as a Linked List where nodes contain digit starting from unit place.
node* num_to_llist(int);

// Function to dispaly generated Linked List.
void show_llist(node*);

// Required function to perform task as demanded.
node* add_nums_in_llist(node*, node*);

void main(){
    
    node *head1, *head2;
    int num1, num2;
    printf("Enter two numbers:\n");
    scanf("%d%d", &num1, &num2);
    
    head1 = num_to_llist(num1);
    show_llist(head1);
    
    head2 = num_to_llist(num2);
    show_llist(head2);

    node *sum;
    sum = add_nums_in_llist(head1, head2); // Function called to perform addition.
    show_llist(sum); // Dispaly result.
}

// Function to store integer as a Linked List where nodes contain digit starting from unit place.
node* num_to_llist(int number){
    node* head = (node*)malloc(sizeof(node));
    if (number==0){
        head->data = 0;
        head->link = NULL;
        return head;
    }

    node* temp;
    temp = head;
    // Store digits of integer at node. 
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

// Function to dispaly generated Linked List.
void show_llist(node* head){
    printf("\n");
    while(head->link){
        printf("%d ->", head->data);
        head = head->link;
    }
    printf("%d", head->data);
}

// Required function to perform task as demanded.
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

    node *head; // Make a temporary Linked List, to be used to handle number having more digits. Helful to avoid repetitive coding.
    head = NULL; // Assign NULL explicitly, otherwise it initialized by garbage value, we don't want that.
    
    if(head2->link){ // head2 have some more digits
        head = head2->link;
    }
    else if(head1->link){ // head1 have some more digits
        head = head1->link;
    }
    else{ // both nums have same number of digits.
        int added = head1->data + head2->data + carry;
        temp->data = added%10;
        carry = added/10;
        temp->link = NULL;
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
        if (head){// If no carry and more digits are there, just link it to temp end(to save some memory).
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
