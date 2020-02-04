#include<stdio.h> #include<stdlib.h>
struct node{
int data; struct node *link;
struct node* insert(struct node* list, int); struct node* delete(struct node* list, int); void traverse(struct node* list); void search (struct node* list, int);
int main() {
int choice; struct node* list=(struct node *) malloc(sizeof(struct node)); list=NULL; printf("************Menu **********\n"); int exit=0; while(exit==0) {
printf("1. Insertion\n2. Deletion\n3. Traversing\n4. Searching\n5. Exit\n"); printf("Enter choice:"); scanf("%d", &choice); switch(choice) { case 1: {
int where; printf("\nWhere do you want to insert: \n"); printf("1. At begining\n2. At specific position\n3. At end\n"); scanf("%d",&where); list = insert(list, where); break;
case 2:{
int position; printf("\nWhich position do you want to delete: "); scanf("%d", &position);
