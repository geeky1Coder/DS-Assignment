#include <bits/stdc++.h>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int l, int r)
{
    int pivot = l;
    while (l < r)
    {
        if (pivot == l)
        {
            if (arr[pivot] < arr[r])
            {
                r--;
            }
            else
            {
                swap(arr[pivot], arr[r]);
                pivot = r;
            }
        }
        else
        {
            if (arr[pivot] > arr[l])
            {
                l++;
            }
            else
            {
                swap(arr[pivot], arr[l]);
                pivot = l;
            }
        }
    }
    return pivot;
}
void quickSort(int arr[], int low, int high)
{
    int pivot = 0;
    if (low < high)
    {
        pivot = partition(arr, low, high);
        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}
int main()
{
    int arr[] = {25, 10, 30, 15, 20, 28, 44, 8};
    int n = sizeof(arr) / sizeof(arr[0]);
    quickSort(arr, 0, n - 1);
    for (int i = 0; i < n; ++i)
    {
        cout << arr[i] << " ";
    }
    return 0;
}