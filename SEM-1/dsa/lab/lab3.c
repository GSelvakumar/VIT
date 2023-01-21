// interpolation search algorithm for a sorted array

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

int arr[MAX];

void create();
void display();
int interpolationSearch(int, int);

int main()
{
    int item, pos;

    create();

    printf("Enter the item which you want to search: ");
    scanf("%d", &item);

    pos = interpolationSearch(item, MAX);

    if (pos != -1)
    {
        printf("Item %d found at position %d \n", item, pos + 1);
    }
    else
    {
        printf("Item %d not found in the list \n", item);
    }

    return 0;
}

void create()
{
    int i;

    printf("Enter the elements of the array: \n");
    for (i = 0; i < MAX; i++)
    {
        scanf("%d", &arr[i]);
    }
}

void display()
{
    int i;

    printf("Elements of the array: \n");
    for (i = 0; i < MAX; i++)
    {
        printf("%d ", arr[i]);
    }
    printf(" \n");
}

int interpolationSearch(int item, int size)
{
    int low, mid, high;

    low = 0;
    high = size - 1;

    while (low <= high)
    {
        mid = low + ((item - arr[low]) * (high - low)) / (arr[high] - arr[low]);

        if (item == arr[mid])
        {
            return mid;
        }
        else if (item < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;
}

// Output

// Enter the elements of the array:
// 1
// 2
// 3
// 4
// 5
// 6
// 7
// 8
// 9
// 10
// 11
// 12
// 13

// Enter the item which you want to search: 5

// Item 5 found at position 5
