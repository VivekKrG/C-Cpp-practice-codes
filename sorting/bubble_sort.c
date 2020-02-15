/*
Assignment-1
Q1. Write a program to sort an array in user defined function.
*/
#include<stdio.h>

void arraysort(int *ar,int size);

main()
	{
		int size;
		printf("Enter size of array=");
		scanf("%d",&size);
		int array[size];
		for (int j=0; j<size; j++)
			{
				printf("Enter Element %d:\n",j+1);
				scanf("%d",&array[j]);
			}
		printf("Sorted Array is following:\n");
		arraysort(array, size);
		for (int j=0; j<size; j++)
			{
				printf("%d ",array[j]);
			}
	}

void arraysort(int *ar,int size)
    {
		for (int i=0; i<size; i++)
		{
			for (int j=0; j<size; j++)
			{
				if ( ar[i]>ar[j])
				{
					int temp= ar[i];
					ar[i]=ar[j];
					ar[j]=temp;
				}
			}
		}
	}

