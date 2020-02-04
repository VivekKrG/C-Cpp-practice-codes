#include <stdio.h>
#include<math.h>
int primes(int n)
{
    int prime[100];
    for(int i = 0; i< 100; i++) prime[i] = 0;

    int count = 0;
    while (n%2 ==0 && n>2)
    {
        n /=2;
        count++;
    }
    prime[0] = count;
    int k =1;
    for (int i =0; i < sqrt(n)+1; i += 2)
    {
        count = 0;
        while (n%i == 0)
        {
            n /= i;
            count++;
        }
        if (count) prime[k++] = count;
    }

    if (n > 2) prime[k] = 1;

    int even = prime[0];
    int odd = 1;
    for(int i = 1; i <= k; i++)
    {
        odd *= prime[i] + 1;
    }
    even *= odd;
    if (odd - even <= 2 && odd - even >= -2)
    {
        return 1;
    }
    else return 0;
}

int main()
{
    int test;
    scanf("%d", &test);
    for(int cas=0; cas < test; cas++)
    {
        int L, R;
        int out = 0;
        scanf("%d%d", &L, &R);
        for(int j = L; j <= R; j++)
        {
            if (primes(j)==1)
                out++;

        }
        printf("Case #%d: %d", cas+1, out);

    }

    return 0;
}
