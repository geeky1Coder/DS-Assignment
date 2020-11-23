#include <bits/stdc++.h>
using namespace std;

//Time Complexity=O(n)
int main()
{
    int arr[10] = {10, 2, 1, 11, 23, 32, 9, 5, 3, 87};
    int el;
    cin >> el;
    int index = -1;
    for (int i = 0; i < 10; ++i)
    {
        if (arr[i] == el)
        {
            index = i;
        }
    }
    if (index != -1)
    {
        cout << arr[index] << " found at index:" << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }
    return 0;
}