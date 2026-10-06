#include <stdio.h>
#define SIZE 50
void heapify(int arr[], int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    if (l < n && arr[l] > arr[largest])
        largest = l;
    if (r < n && arr[r] > arr[largest])
        largest = r;
    if (largest != i)
    {
        int t = arr[i];
        arr[i] = arr[largest];
        arr[largest] = t;
        heapify(arr, n, largest);
    }
}
void heapSort(int arr[], int n)
{
    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);
    // Extract elements from heap
    for (int i = n - 1; i > 0; i--)
    {
        int t = arr[0];
        arr[0] = arr[i];
        arr[i] = t;
        heapify(arr, i, 0);
    }
}
int main()
{
    int n, arr[SIZE];
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    heapSort(arr, n);
    printf("Sorted array (Ascending using Heap): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}






--OUTPUT
Enter number of elements: 5
Enter 5 elements: 7 1 6 2 3
Sorted array (Ascending using Heap): 1 2 3 6 7
