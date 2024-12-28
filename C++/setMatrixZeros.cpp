#include<bits/stdc++.h>
using namespace std;

/*
    Given a matrix if an element in the matrix is 0 then you 
    will have to set its entire column and row to 0 and then 
    return the matrix.
    Assume matrix is of type n*m
    Brute Force approach -> 
        Iterate thorugh the matrix and find the zeroes,
        make all row and col
        cells corresponding to that zero cell as -1
        TC - O((n*m)*(n+m)+(n*m)) => O(pow(n,3))    
    
    Better approach -> 

*/

void setMatrixZeroes_better(int arr[n][m], int n, int m)
{
    int rowArr[n] = {0};
    int colArr[m] = {0};

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(arr[i][j] == 0)
            {
                rowArr[i] = 1;
                colArr[j] = 1;
            }
        }
    }

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(rowArr[i] == 1 || colArr[j] == 1)
            {
                arr[i][j] = 0;
            }
        }
    }
}

int main()
{
    int n1,n2,k;

    cin >> n1;
    cin >> n2;
    int arr1[n1][n2];
    for(int i=0; i<n1; i++)
    {
        for(int j=0; j<n2; j++)
        {
            cin >> arr1[i][j];
        }
    }

    setMatrixZeroes_better(arr1,n1,n2); 
       
    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    /*
    for(auto it: ans)
    {
        cout << it << " ";
    }
    */
}