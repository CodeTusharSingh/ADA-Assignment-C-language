#include <stdio.h>

int gcd(int n, int m)
{
    if (n == m)
    {
        return n;
    }
    else if (n > m)
    {
        if (m == 0)
        {
            return n;
        }
        if (n % m == 0)
        {
            return m;
        }
        else
        {
            return gcd(m, n % m);
        }
    }
    else if (m > n)
    {
        if (n == 0)
        {
            return m;
        }
        if (m % n == 0)
        {
            return n;
        }
        else
        {
            return gcd(n, m % n);
        }
    }
}

int main()
{
    printf("%d \n", gcd(4, 522));
    return 0;
}