#include<bits/stdc++.h>
using namespace std;

/*
    Given a Matrix, print the given matrix in spiral order.

    Solution -> 
        Use 4 markers top, left, right and bottom.
        First go from left to right, then top to 
        bottom, then right to left and finally bottom 
        to top.
        Repeat this until we reach the centre.

*/

void printMatrixInSpiral(vector<vector<int>> matrix)
{
    int top = 0, left = 0;
    int right = matrix[0].size()-1, bottom = matrix.size()-1;
    while(top <= bottom && left <= right)
    {
        for(int i=left; i<=right; i++)
        {
            cout << matrix[top][i] << " ";
        }
        top++;

        for(int i=top; i<=bottom; i++)
        {
            cout << matrix[i][right] << " ";
        }
        right--;

        if(top<=bottom)
        {
            for(int i=right; i>=left; i--)
            {
                cout << matrix[bottom][i] << " ";
            }
            bottom--;
        }

        if(left<=right)
        {
            for(int i=bottom; i>=top; i--)
            {
                cout << matrix[i][left] << " ";
            }
            left++;
        }   
    }
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
    //ansVect = rotateBruteForce(arr1);
    printMatrixInSpiral(arr1); 
       
    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    /*
    for (auto it : ansVect) 
    {
        for (auto ele : it) 
        {
            cout << ele << " ";
        }
        cout << endl;
    }
    */
}