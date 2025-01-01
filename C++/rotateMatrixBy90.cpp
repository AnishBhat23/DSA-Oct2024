#include<bits/stdc++.h>
using namespace std;

/*
    Given a NxN matrix, rotate it clockwise by 90 degrees. 
    Brute Force Approach -> 
        From the pattern formed by rotating each matrix manually, 
        we see that each element at matrix[i][j] takes the spot
        matrix[j][n-1-i] where n is the length of row/col in NxN
        matrix.

        TC -> O(pow(n,2))
        SC -> O(pow(n,2))
    
    Optimal Approach-> 
        We will try to get the answer in place without using extra 
        space. First step will be to transpose the matrix 
        and the next step will be to reverse the rows to get the answer. 

        TC -> O(pow((N/2),2)) + O(N*(N/2))
        SC -> O(1)


*/

vector<vector<int>> rotateBruteForce(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> result(n, vector < int > (n, 0)); // Initialize NxN to zeroes
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            result[j][n-1-i] = matrix[i][j];
        }
    }

    return result;
}

void rotateOptimal(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            swap(matrix[i][j], matrix[j][i]);    
        }
    }

    for(int i=0; i<n; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
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
    ansVect = rotateBruteForce(arr1);
    rotateOptimal(arr1); 
       
    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    
    for (auto it : arr1) 
    {
        for (auto ele : it) 
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}