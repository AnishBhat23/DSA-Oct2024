#include<bits/stdc++.h>
using namespace std;

/*
    You are given a read-only array of N integers with values also in the range [1, N] 
    both inclusive. Each integer appears exactly once except A which appears twice and 
    B which is missing. The task is to find the repeating and missing numbers A and B 
    where A repeats twice and B is missing.

    Brute Force Approach -> For all numbers from 1 to N, use linear search to find the 
                            number of occurances of each element. 
    TC -> O(pow(n,2)) 
    SC -> O(1)

    Better Approach -> Use a hashMap to store the occurances of all the elements and
                       return the element with occurances 2 and 0. 
    TC -> O(2N)
    SC -> O(N)

    Optimal Approach 1 -> Use the formula for summation S = n*(n+1)/2 and formula for 
                          square of summation 

*/

vector<int> findRepeatingAndMissingNumber(vector<int> arr)
{
    int n = arr.size();
    int missing = -1, repeating = -1;

    for(int i=1; i<=n; i++)
    {
        int cnt = 0;
        for(int j=0; j<n; j++)
        {
            if(arr[j] == i)  
            {
                cnt++;
            }  
        }

        if(cnt == 2) repeating = i;
        else if(cnt == 0) missing = i;

        if(repeating != -1 && missing != -1)
            break;
    }

    return {repeating, missing};
}

vector<int> findRepeatingAndMissingNumber_optimal(vector<int> arr)
{
    long long n = arr.size();
    
    long long X=0, Y=0;


    long long Sn = (n*(n+1))/2;
    long long S2n = (n*(n+1)*((2*n) + 1))/6;

    long long S=0, S2=0;
    for(int i=0; i<n; i++)
    {
        S += (long long)arr[i];
        S2 += ((long long)arr[i] * (long long)arr[i]);
    }

    long long res1 = S - Sn; //X - Y
    long long res2 = S2 -S2n;
    res2 = res2/res1; // X + Y
    X = (res2+res1)/2;
    Y = X - res1;

    return {(int)X, (int)Y};

}

int main()
{
    int len1,len2,k;

    cin >> len1;
    vector<int> arr1;
    for(int i=0;i<len1;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    vector<int> ans;
    ans = findRepeatingAndMissingNumber_optimal(arr1);
    
    for (auto it : ans) 
    {
        cout << it << " ";   
    }   

    cout << endl;
    
}