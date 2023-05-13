#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <float.h>

struct Point
{
    double x, y;
};

// Function to calculate the Euclidean distance between two points
double distance(struct Point p1, struct Point p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

// Function to compare points based on their x-coordinate
int compareX(const void *a, const void *b)
{
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return (p1->x - p2->x);
}

// Function to compare points based on their y-coordinate
int compareY(const void *a, const void *b)
{
    struct Point *p1 = (struct Point *)a;
    struct Point *p2 = (struct Point *)b;
    return (p1->y - p2->y);
}

// Function to find the minimum of two double values
double min(double x, double y)
{
    return (x < y) ? x : y;
}

// Function to find the closest pair of points in a strip of given size
double stripClosest(struct Point strip[], int size, double d)
{
    double minDist = d;

    // Sort the points based on y-coordinate
    qsort(strip, size, sizeof(struct Point), compareY);

    // Find the minimum distance in the strip by checking each point
    for (int i = 0; i < size; ++i)
    {
        for (int j = i + 1; j < size && (strip[j].y - strip[i].y) < minDist; ++j)
        {
            double dist = distance(strip[i], strip[j]);
            if (dist < minDist)
            {
                minDist = dist;
            }
        }
    }

    return minDist;
}

// Recursive function to find the closest pair of points
double closestUtil(struct Point points[], int n)
{
    // Base case: if the number of points is 2 or 3
    if (n <= 3)
    {
        double minDist = DBL_MAX;
        for (int i = 0; i < n; ++i)
        {
            for (int j = i + 1; j < n; ++j)
            {
                double dist = distance(points[i], points[j]);
                if (dist < minDist)
                {
                    minDist = dist;
                }
            }
        }
        return minDist;
    }

    // Find the middle point
    int mid = n / 2;
    struct Point midPoint = points[mid];

    // Calculate the minimum distance on the left and right halves
    double leftDist = closestUtil(points, mid);
    double rightDist = closestUtil(points + mid, n - mid);

    // Find the smaller of the two distances
    double minDist = min(leftDist, rightDist);

    // Build a strip that contains points closer than the minimum distance to the middle line
    struct Point strip[n];
    int j = 0;
    for (int i = 0; i < n; i++)
    {
        if (abs(points[i].x - midPoint.x) < minDist)
        {
            strip[j] = points[i];
            j++;
        }
    }

    // Find the minimum distance in the strip
    double stripDist = stripClosest(strip, j, minDist);

    // Return the minimum of the strip distance and the minimum distance from the left and right halves
    return min(stripDist, minDist);
}

// Function to find the closest pair of points
double closestPair(struct Point points[], int n)
{
    // Sort the points based on their x-coordinate
    qsort(points, n, sizeof(struct Point), compareX);

    // Call the recursive helper function to find the closest pair of points
    return closestUtil(points, n);
}

int main()
{
    int n;
    printf("Enter the number of points: ");
    scanf("%d", &n);

    // Allocate memory for the points
    struct Point *points = (struct Point *)malloc(n * sizeof(struct Point));

    // Read the coordinates of the points
    for (int i = 0; i < n; ++i)
    {
        printf("Enter x and y coordinates of point %d: ", i + 1);
        scanf("%lf %lf", &(points[i].x), &(points[i].y));
    }

    // Find the closest pair of points
    double minDistance = closestPair(points, n);

    printf("The closest pair of points has a distance of: %lf\n", minDistance);

    // Free the allocated memory
    free(points);

    return 0;
}
