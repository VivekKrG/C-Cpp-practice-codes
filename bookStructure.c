 ///This program is to implement Book Structure.
#include<stdio.h>

struct book{
    int book_id;
    char title[10];
    char author_name[20];
    float price;
};

void main(){
    printf("***Book Structure***\n");
 /// Creating Book Structure
    struct book mybook;
    printf("Enter ID of the book(Number): ");
    scanf("%d",&mybook.book_id);
    printf("\nEnter Title of the book: ");
    scanf("%s",mybook.title);
    printf("\nEnter Author's Name of the book: ");
    scanf("%s",mybook.author_name);
    printf("\nEnter Price of the book: ");
    scanf("%f",&mybook.price);
/// Traversing Structure
    printf("\n\nDetails of Book structure is following:\n");
    printf("Book ID\t\t\t: %d", mybook.book_id);
    printf("\nBook Title\t\t: %s", mybook.title);
    printf("\nBook Author's Name\t: %s", mybook.author_name);
    printf("\nBook Price\t\t: %f", mybook.price);
    return;
}
