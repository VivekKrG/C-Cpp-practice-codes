#include<stdio.h>
int bin(int *, int, int);
void main(){
    printf("This program is to search an element using Quick Search method\n");
    int n,x;
    printf("Enter length of the array");
    scanf("%d",&n);

    printf("\nEnter sorted array\n");
    int arr[n];
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nEnter Number to search=");
    scanf("%d",&x);
    int check= bin(arr, n,x);
    if(check !=-1)
        printf("Number is present in array");
    else
        printf("Number is not present in array");

    return;
}

int bin(int *arr, int len, int x){
    int check=-1;
    if ( len==0 )
        return check;

    if(x == arr[len/2]){
        check=len/2;
        return check;
    }
    else if(x<arr[len/2])
        return bin(arr, len/2, x);

    else
        return bin(arr + len/2, len/2, x);
}
