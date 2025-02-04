#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of N integers, 
    your task is to find unique triplets 
    that add up to give a sum of zero. 
    In short, you need to return an array 
    of all the unique triplets [arr[a], arr[b], arr[c]] 
    such that i!=j, j!=k, k!=i, and their sum is equal to zero.

    Brute force -> 
        generate all triplets and check whether they add
        up to zero. Return all the unique answer triplets. 

        TC -> O(pow(n,3) * log(number of unique triplets))
        SC -> O(2 * number of unique triplets) as we are using set data structure

    Better Approach ->  
        Reduce a loop by looking directly for the third element using 
        hashing.

        TC -> O(pow(n,2) * log(no. of unique triplets))
        SC -> O(2 * no of unique triplets) + O(N)

    Optimal Approach -> 
        Use a two pointer approach to get the answer triplets 
        without using extra space.

        TC -> O(nlogn) + O(pow(n,2))
        SC -> O(no of unique triplets)

*/


vector<vector<int>> triplet_brute(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n ;j++)
        {
            for(int k = j+1; k<n; k++)
            {
                if(arr[i]+arr[j]+arr[k] == 0)
                {
                    vector<int> temp = {arr[i], arr[j], arr[k]};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


vector<vector<int>> triplet_better(int n, vector<int> &arr)
{
    set<vector<int>> st;
    for(int i = 0; i<n; i++)
    {
        set<int> hashmap;
        for(int j = i+1; j<n ;j++)
        {
            int third = -(arr[i] + arr[j]);
            if(hashmap.find(third) != hashmap.end())
            {
                vector<int> temp = {arr[i], arr[j], third};
                sort(temp.begin(), temp.end());
                st.insert(temp);
            }
            hashmap.insert(arr[j]);
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


vector<vector<int>> triplet_optimal(int n, vector<int> &arr)
{
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for(int i = 0; i<n; i++)
    {
        if(i>0 && arr[i] == arr[i-1]) continue;
        int j = i+1;
        int k = n-1;
        while(j<k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if(sum < 0)
            {
                j++;
            }
            else if(sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                while(j<k && arr[j] == arr[j-1]) j++;
                while(j<k && arr[k] == arr[k+1]) k--;
            }
        }
    }
    return ans;
}



int main()
{
    int len;
    cin >> len;
    vector<int> arr1;
    int temp = 0;
    for(int i=0;i<len;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	} 
    vector<vector<int>> ans = triplet_optimal(len, arr1);

    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */

    for(auto it: ans)
    {
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

}