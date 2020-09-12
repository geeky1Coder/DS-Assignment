#include <bits/stdc++.h>
using namespace std;
#define arr_size 100
//O(n) Time Complexity
void insertion(int array[], int index, int element, int &elements)
{
    if (index > elements + 1)
    {
        return;
    }
    else
    {
        ++elements;
        for (int i = elements; i > index; --i)
        {
            array[i] = array[i - 1];
        }
        array[index] = element;
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
    cout << "Array before insertion of element:";
    for (int i = 0; i < elements + 1; ++i)
    {
        array[i] = s_array[i];
        cout << array[i] << " ";
    }
    cout << endl;

    int index;
    cin >> index;
    int element;
    cin >> element;
    insertion(array, index, element, elements);
    cout << endl;
    cout << "Array after insertion of:" << element << "at index" << index << ":";
    for (int i = 0; i < elements + 1; ++i)
    {
        cout << array[i] << " ";
    }
    return 0;
}