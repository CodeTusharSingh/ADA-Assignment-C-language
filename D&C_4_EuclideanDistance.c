#include <stdio.h>
#include <math.h>
int res = 0;
// A function to compute the square of the difference between two numbers
float square_diff(float x, float y)
{
    return (y - x) * (y - x);
}

// A recursive function to compute the Euclidean distance between two points
// p and q are arrays of size 2 that store the x and y coordinates of the points
float euclidean_distance(float p[], float q[], int n)
{
    // Base case: n is 0, return 0
    if (n == 0)
    {
        return 0;
    }
    // Divide: compute the square of the difference between the last coordinates of p and q
    float last = square_diff(p[n - 1], q[n - 1]);
    res += last;
    // Conquer: recursively compute the Euclidean distance between the first n-1 coordinates of p and q
    euclidean_distance(p, q, n - 1);
    // Combine: return the square root of the sum of last and rest
    return sqrt(res);
}

int main()
{
    float a[] = {1, 2};
    float b[] = {5, 6};
    int n = sizeof(a) / sizeof(a[0]);
    printf("%f \n", euclidean_distance(a, b, n));
    return 0;
}
