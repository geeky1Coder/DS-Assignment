#include <bits/stdc++.h>
using namespace std;
#define arr_size 100
//O(n) TimeComplexity
void deletion(int array[], int index, int &elements)
{
    if (index < 0 || index > elements)
    {
        return;
    }
    else
    {
        array[index] = -1;
        for (int i = index; i < elements; ++i)
        {
            array[i] = array[i + 1];
        }
        --elements;
    }
}
int main()
{
    int array[arr_size];

    for (int i = 0; i < arr_size; ++i)
    {
        array[i] = -1;
    }
    int elements = 9;
    int s_array[elements] = {1, 4, 3, 8, 9, 10, 21, 20, 16, 13};
    cout << "Array before deletion of element:";
    for (int i = 0; i < elements + 1; ++i)
    {
        array[i] = s_array[i];
        cout << array[i] << " ";
    }
    cout << endl;

    int index;
    cin >> index;
    deletion(array, index, elements);
    cout << endl;
    cout << "Array after deletion of element at index " << index << ":";
    for (int i = 0; i < elements + 1; ++i)
    {
        cout << array[i] << " ";
    }
    return 0;
}