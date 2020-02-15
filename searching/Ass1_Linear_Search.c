#include<stdio.h>

void linear_search(int *a, int n,int k);

int main()
{
	int size,k;
    printf("Enter size of array=");
    scanf("%d",&size);
    int array[size];
    for (int j=0; j<size; j++)
    {
        printf("Enter element %d:\n",j+1);
        scanf("%d",&array[j]);
    }
	printf("\nEnter the number to be searched:");
	scanf("%d",&k);
	linear_search(array,size,k);
	return 0;
}
void linear_search(int *a, int n,int k)
{
 	int i;
 	for(i=0;i<n;i++)
 	{
 		if(k ==a[i])
		{
			printf("\nElement found at %d position.\n",i+1);
		 	break;
		}
	}
	if(i==n)
	{
		printf("\nElement is not found\n");
	}
}
