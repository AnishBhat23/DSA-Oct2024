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
        Create a row and col arrays which will hold the value of their
        respective cols and rows, ie even if one element of this row or col
        is zero, the array index will hold the value zero.

        TC - O(2*n*m)
        SC - O(n+m)

    Optimal Approach -> 
        Improving on the better approach, we can choose to store the values
        of row and col in the matrix itself by taking the first row and 
        first col as the col and row respectively. 
        Then make all the other elements of the matrix except these two 
        zero based the col and row values. 

        TC - O(2*n*m)
        SC - O(1)

*/

vector<vector<int>> setMatrixZeroes_better(vector<vector<int>> &matrix, int n, int m) 
{
    int row[n] = {0}; // row array
    int col[m] = {0}; // col array

    // Traverse the matrix:
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] == 0) 
            {
                // mark ith index of row wih 1:
                row[i] = 1;

                // mark jth index of col wih 1:
                col[j] = 1;
            }
        }
    }

    // Finally, mark all (i, j) as 0
    // if row[i] or col[j] is marked with 1.
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (row[i] || col[j]) 
            {
                matrix[i][j] = 0;
            }
        }
    }

    return matrix;
}

vector<vector<int>> setMatrixZeroes_optimal(vector<vector<int>> &matrix, int n, int m) 
{

    //int row[n] = {0}; // row array will be matrix[..][0]
    //int col[m] = {0}; // col array will be matrix[0][..]
    int col0 = 1;


    // Traverse the matrix:
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < m; j++) 
        {
            if (matrix[i][j] == 0) 
            {
                // mark ith index of row wih 1:
                matrix[i][0] = 0;

                // mark jth index of col wih 1:
                if(j != 0)
                {
                    matrix[0][j] = 0;
                }
                else
                {
                    col0 = 0;
                }
            }
        }
    }

    for(int i=1; i<n ; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(matrix[i][j] != 0)
            {
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                {
                    matrix[i][j] = 0;
                }
            }
        }
    }

    if(matrix[0][0] == 0)
    {
        for(int j=0; j<m; j++)
        {
            matrix[0][j] = 0;
        }
    }

    if(col0 == 0)
    {
        for(int i=0; i<n; i++)
        {
            matrix[i][0] = 0;
        }
    }
    
    return matrix;
}

int main()
{
    int rows,cols,k;

    cin >> rows;
    cin >> cols;
    vector<vector<int>> arr1;
    int temp = 0;
    for(int i=0;i<rows;++i) 
    { 
		//Create a vector  
		vector<int> row; 
		for(int j=0;j<cols;++j)
        { 
			int value; 
			cin >> value; 
			row.push_back(value); 
		} 
		//Push the row in matrix 
		arr1.push_back(row); 
	} 

    vector<vector<int>> ansVect;
    ansVect = setMatrixZeroes_optimal(arr1,rows,cols); 
       
    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    
    for (auto it : ansVect) 
    {
        for (auto ele : it) 
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}