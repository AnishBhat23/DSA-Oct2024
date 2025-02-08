#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of integers A and an integer B. 
    Find the total number of subarrays having bitwise 
    XOR of all elements equal to k.

    Brute Force -> Generate all the subarrays with XOR equal to zero in an
                   iterative fashion. 
    
    TC -> O(pow(n,3))
    SC -> O(1)

    Better Approach -> Reduce the time complexity by N by generating the 
                       XOR sum during the second iteration of the array. 

    TC -> O(pow(n,2))
    SC -> O(1)                   

    Optimal Approach -> In this approach, we are going to use the concept 
                        of the prefix XOR to solve this problem. Here, the 
                        prefix XOR of a subarray ending at index i, 
                        simply means the XOR of all the elements of that subarray.
    TC -> O(N * logN)  (because using map)
    SC -> O(N)
*/

int subarraysWithSumK_better(vector < int > a, int b) {
    
    int n = a.size();
    int ans = 0;

    for(int i =0; i<n; i++)
    {
        int XOR = 0;
        for(int j = i; j<n ;j++)
        {
            XOR ^= a[j];

            if(XOR == b)
            {
                ans++;
            }
        }
    }

    return ans;
}

int subarraysWithSumK_optimal(vector < int > a, int b) {
    
    int n = a.size();
    int ans = 0;
    int XOR = 0;
    int x = 0;
    map<int,int> frontXOR;
    frontXOR[0]++;
    for(int i=0; i<n; i++)
    {
        XOR ^= a[i];

        x = XOR ^ b;
        if(frontXOR.find(x) != frontXOR.end())
        {
            ans += frontXOR[x];
        }

        frontXOR[XOR]++; 
    } 
    return ans;
}


int main()
{
    int len,k;

    cin >> k;
    cin >> len;
    vector<int> arr1;
    int temp = 0;
    for(int i=0;i<len;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	} 

    int ans = subarraysWithSumK_optimal(arr1,k);
    cout << ans << endl;
       
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