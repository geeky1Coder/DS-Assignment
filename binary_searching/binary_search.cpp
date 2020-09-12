#include <bits/stdc++.h>
using namespace std;

//Time Complexity=O(log(n))
int binary_search(int arr[], int start, int end, int target)
{
    int mid = start + (end - start) / 2;
    if (start > end)
    {
        return -1;
    }
    if (target > arr[mid])
    {
        return binary_search(arr, mid + 1, end, target);
    }
    else if (target < arr[mid])
    {
        return binary_search(arr, start, mid - 1, target);
    }
    else
    {
        return mid;
    }
}

int main()
{
    int array[] = {3, 4, 12, 14, 17, 21, 32, 45, 49};
    int el;
    cin >> el;
    int size = sizeof(array) / sizeof(array[0]);
    int index = binary_search(array, 0, size - 1, el);
    if (index != -1)
    {
        cout << array[index] << " found at index:" << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}