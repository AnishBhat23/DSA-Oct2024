#include<bits/stdc++.h>
using namespace std;

/*
    
*/


int maxProductSubarray_brute(vector<int> arr)
{
    int n = arr.size();
    int max_prod = INT_MIN;
    for(int i=0; i<n-1; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int prod = 1;
            for(int k=i; k<j; k++)
            {
                prod *= arr[k];
            }
            max_prod = max(max_prod,prod);
        }
    }

    return max_prod;
}

int maxProductSubarray_better(vector<int> arr)
{
    int n = arr.size();
    int max_prod = arr[0];
    for(int i=0; i<n-1; i++)
    {
        int prod = arr[i];
        for(int j=i+1; j<n; j++)
        {
            max_prod = max(max_prod,prod);
            prod *= arr[j];
        }
        max_prod = max(max_prod,prod);
    }

    return max_prod;
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

    int ans;
    ans = maxProductSubarray_brute(arr1);

    cout << ans << " ";      
    
}