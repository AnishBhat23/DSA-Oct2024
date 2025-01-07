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

    ans2 = pascalTriangleTwo(r);

    for(auto it : ans2)
    {
        cout << it << " ";
    }

    
}