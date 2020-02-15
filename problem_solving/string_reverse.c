/*  Assignment1
    Q2. Write a program to reverse a string using pointers.
*/
#include<stdio.h>

void reverse(char *str);

void main()
{
	char string[20];
	printf("Enter string to reverse it:\n");
	scanf("%s", string);
	reverse(string);
	printf("\n%s", string);
}
void reverse(char *str)
{
	int i=0;
	do
	{
		++i;
	}
	while(str[i]!=0);

	for (int j=0; j<i/2;j++)
	{
		char temp=str[j];
		str[j]=str[i-j-1];
		str[i-j-1]=temp;
	}
}
