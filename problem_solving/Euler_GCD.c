#include <stdio.h>

int gcd(int n, int m)
{
    int temp=0;
    if (n<m)
    {
        temp=n;
        n=m;
        m=temp;
    }

    while (n%m !=0)
    {
        int temp=m;
        m= n%m;
        n=temp;
    }
    return m;
}
void main()
{
    int n, m;
    printf("Enter two numbers\n");
    scanf("%d %d", &n,&m);
    printf("gcd is %d", gcd(n,m));
}
