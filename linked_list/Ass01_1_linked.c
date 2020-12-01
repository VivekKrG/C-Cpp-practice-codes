#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *link;
};

struct node* insert(struct node* list, int);
struct node* delete_node(struct node* list, int);
void traverse(struct node* list);
void search(struct node* list, int);

int main() {
    int choice;
    struct node* list=(struct node *) malloc(sizeof(struct node));
    list=NULL;
    printf("************Menu **********\n");
    int exit=0;
    while(exit==0) {
            printf("1. Insertion\n2. Deletion\n3. Traversing\n4. Searching\n5. Exit\n");
            printf("Enter choice:");
            scanf("%d", &choice);
            int where, position, value;
            switch(choice) {
                case 1:
                    printf("\nWhere do you want to insert: \n");
                    printf("1. At beginning\n2. At specific position\n3. At end\n");
                    scanf("%d",&where);
                    list = insert(list, where);
                    break;
                case 2:
                    printf("\nWhich position do you want to delete: ");
                    scanf("%d", &position);
                    list = delete_node(list, position);
                    break;
                case 3:
                    // ToDo traversing
                    traverse(list);
                    break;
                case 4:
                    // ToDo Searching
                    printf("Enter value to search:");
                    scanf("%d", &value);
                    search(list, value);
                    break;
                case 5:
                    exit = 1;
                    break;
                default:
                    printf("Wrong input.");
                    break;
            }
    }
}

struct node* insert(struct node* list, int position){
    struct node* temp;

    struct node* new_node =(struct node *) malloc(sizeof(struct node));
    int value, specific_position, count;
    printf("Enter number to insert:\n");
    scanf("%d", &value);
    new_node->data = value;

    switch(position){
        case 1:
            // Insert at beginning
            if (list != NULL)
                new_node->link = list;
            else{
                new_node->link = list;
                new_node->link = NULL;
            }
            return new_node;
            break;
        case 2:
            // Insert at specific position, get that position
            printf("Enter specific position:\n");
            scanf("%d", &specific_position);
            temp = list;
            count = 1;
            while (count < specific_position -1){
                temp = temp->link;
                count++;
            }
            new_node->link = temp->link;
            temp->link = new_node;
            return list;
            break;
        case 3:
            // Insert at last
            temp = list;
            while (temp->link != NULL)
                temp = temp->link;
            temp->link = new_node;
            new_node->link = NULL;
            return list;
            break;
        default:
            printf("Wrong input.");
            break;
    }
};

struct node* delete_node(struct node* list, int position){
    struct node* temp;
    temp = list;
    if (position == 1){
        list = list->link;
        free(temp);
    }
    else{
        int current_position = 1;
        while (current_position < position-1){
            temp = temp->link;
            current_position++;
        }
        struct node* temp2;
        temp2 = temp->link;
        temp->link = temp->link->link;
        free(temp2);
    }
    return list;
};

void traverse(struct node* list){
    if (list != NULL){
        struct node* temp;
        temp = list;
        while (temp->link != NULL){
            printf("%d ", temp->data);
            temp = temp->link;
        }
        printf("%d\n", temp->data);
    }
    else
        printf("NULL\n");
    return;
}

void search(struct node* list, int value){
    struct node* temp;
    temp = list;
    int position = 1;
    while (temp->link != NULL){
        if (temp->data == value){
            printf("Value found at %d\n", position);
            return;
        }
        else{
            temp = temp->link;
            position++;
        }
    }
    if (temp->data == value)
        printf("Value found at %d\n", position);
    else
        printf("Value not found!!\n");
    return;
}
