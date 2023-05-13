#include <stdio.h>
#include <math.h>

long long int karatsuba(long long int x, long long int y)
{
    if (x < 10 || y < 10)
    {
        return x * y;
    }

    int n = fmax(log10(x) + 1, log10(y) + 1);
    int half = ceil(n / 2.0);

    long long int a = x / pow(10, half);
    long long int b = x % (long long int)pow(10, half);
    long long int c = y / pow(10, half);
    long long int d = y % (long long int)pow(10, half);

    long long int ac = karatsuba(a, c);
    long long int bd = karatsuba(b, d);
    long long int ad_plus_bc = karatsuba(a + b, c + d) - ac - bd;

    return ac * (long long int)pow(10, 2 * half) + ad_plus_bc * (long long int)pow(10, half) + bd;
}

int main()
{
    long long int x, y;
    printf("Enter two numbers to multiply: ");
    scanf("%lld %lld", &x, &y);

    long long int result = karatsuba(x, y);
    printf("Multiplication result: %lld\n", result);

    return 0;
}
