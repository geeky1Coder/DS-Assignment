#include <bits/stdc++.h>
using namespace std;

void swap(int &x, int &y)
{
	int temp = x;
	x = y;
	y = temp;
}
void printArr(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void bubbleSort(int arr[], int n)
{
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < (n - i - 1); ++j)
		{
			if (arr[j + 1] < arr[j])
			{
				swap(arr[j + 1], arr[j]);
			}
		}
	}
}

int main()
{
	int n = 5;
	int arr[n] = {10, 5, 9, 12, 7};
	printArr(arr, n);
	bubbleSort(arr, n);
	printArr(arr, n);
	return 0;
}