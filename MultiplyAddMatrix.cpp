#include <bits/stdc++.h>
using namespace std;

void matrix_addition(int mat1[][3], int mat2[][3], int result[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            result[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
}
void matrix_multiplication(int mat1[][3], int mat2[][3], int result[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            for (int k = 0; k < 3; k++)
            {
                result[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void printMatrix(int matrix[][3])
{
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}
int main()
{
    int mat1[3][3] = {{3, 2, 1},
                      {1, 3, 0},
                      {2, 4, 5}};
    int mat2[3][3] = {{1, 3, 0},
                      {2, 4, 5},
                      {5, 1, 4}};
    int res[3][3] = {{0, 0, 0},
                     {0, 0, 0},
                     {0, 0, 0}};
    matrix_addition(mat1, mat2, res);
    printMatrix(res);
    cout << endl;
    matrix_multiplication(mat1, mat2, res);
    printMatrix(res);
    return 0;
}