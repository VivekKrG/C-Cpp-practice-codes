/*Euler’s Totient function ?(n) for an input n is count of numbers in {1, 2, 3, …, n}
that are relatively prime to n, i.e., the numbers whose GCD (Greatest Common Divisor) with n is 1. */
#include <stdio.h>
void main()
{
    int n;
    printf("Please Enter a number");
    scanf("%d",&n);

    int num=1, i,j;
    for( i=2; i<n; i++)
    {
        int temp=0;
        for( j=2; j<=i; j++)
        {
            if (i%j==0 && n%j==0)//eska v koi divider hy
            {
                temp++;
            }
        }
        if (temp ==0)
        {
            printf("(%d, %d)\n",n ,i);
            num++;
        }
    }
    printf("%d",num);
}
