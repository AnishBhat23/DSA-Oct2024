#include<bits/stdc++.h>
using namespace std;

/*
    Given row number r and column number c. 
    Print the element at position (r, c) in Pascal’s triangle.

    Naive Approach -> 
        Use the formula (r-1)C(c-1) to get the element at position
        (r,c) in Pascal's Triangle
        TC -> O(N)+O(r)+O(n-r)
        SC -> O(1)

    Better Approach -> 
        Imporving upon the naive approach,
        use, we can loop through 0 to c and 
        get (res * r)/c every iteration to arrive at 
        the final solution. 

        TC -> O(c);
        SC -> 1;
*/ 


long pascalTriangleOne(int r, int c)
{ 
    long res = 1;
    for(int i=0; i<c; i++)
    {
        res *= (r-i);
        res /= (i+1);
    }   
    return res;
}


/*
    Given the row number n. Print the n-th row of Pascal’s triangle.

    Naive Approach -> 
        Recursively loop using the formula 
        nCr(n-1,c-1)
        TC -> O(n*r)
    
    Better Approach -> 
        Using this formula : res * (row-col/col)
        We can get the required row
        TC -> O(N)
        SC -> O(1)

*/


vector<long> pascalTriangleTwo(int r)
{
    vector<long> ans;
    long res = 1;
    ans.push_back(res);
    for(int i=1; i<r; i++)
    {
        res = res * (r-i);
        res = res/i;
        ans.push_back(res);
    }
    return ans;
}

/*
    Given the number of rows n. 
    Print the first n rows of Pascal’s triangle.

    Brute Force Approach -> 
        Combine the naive approach of variation 1 and 2
        run the code of the vartiation 2 inside a loop
        to generate the n rows of the pascal's triangle

    TC -> O(n*n*r) ~ O(pow(n,3))
    SC -> O(1)

    Optimal Approach -> 
        Generate each row in O(N) time using the 
        optimal approach of variation 2
    
    TC -> 
*/


int nCr(int n, int r) {
    long long res = 1;

    // calculating nCr:
    for (int i = 0; i < r; i++) {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return (int)(res);
}

vector<vector<int>> pascalTriangle_naive(int n) {
    vector<vector<int>> ans;

    //Store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        vector<int> tempLst; // temporary list
        for (int col = 1; col <= row; col++) {
            tempLst.push_back(nCr(row - 1, col - 1));
        }
        ans.push_back(tempLst);
    }
    return ans;
}

vector<int> generateRow(int row) {
    long long ans = 1;
    vector<int> ansRow;
    ansRow.push_back(1); //inserting the 1st element

    //calculate the rest of the elements:
    for (int col = 1; col < row; col++) {
        ans = ans * (row - col);
        ans = ans / col;
        ansRow.push_back(ans);
    }
    return ansRow;
}

vector<vector<int>> pascalTriangle(int n) {
    vector<vector<int>> ans;

    //store the entire pascal's triangle:
    for (int row = 1; row <= n; row++) {
        ans.push_back(generateRow(row));
    }
    return ans;
}


int main()
{
    int r, c;
    long ans1;
    vector<long> ans2;
     
    cin >> r;
    cin >> c;
/*
    ans1 = pascalTriangleOne(r-1,c-1);
    cout << "The element is " << ans1 << endl;
*/
/*
    ans2 = pascalTriangleTwo(r);

    for(auto it : ans2)
    {
        cout << it << " ";
    }
*/
    vector<vector<int>> ans = pascalTriangle(r);
    for (auto it : ans) {
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "\n";
    }
    
}