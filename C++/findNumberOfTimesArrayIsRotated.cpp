#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array arr of size N, sorted in ascending order 
    (with distinct values). Now the array is rotated between 1 to N 
    times which is unknown. Find how many times the array has been rotated. 

    TC -> O(log2N)
    SC -> O(1)
*/
int minIdx(int idx1, int idx2, vector<int> &arr)
{
    if(arr[idx1] <= arr[idx2])
    {
        return idx1;
    }
    else
    {
        return idx2;
    }
}

int search_in_rotated_sorted_array(vector<int> &arr, int high, int low, int ansIdx)
{
    if(low == high)
    {
        return minIdx(low,ansIdx,arr);
    }

    int mid = (high+low)/2;

    if(arr[low] <= arr[high])
    {
        return minIdx(low,ansIdx,arr);
    }

    if(arr[low] <= arr[mid])
    {
        low = mid+1;
        ansIdx = minIdx(ansIdx, low, arr);
        return search_in_rotated_sorted_array(arr,high,low,ansIdx);
    }
    else
    {
        high = mid-1;
        ansIdx = minIdx(ansIdx, mid, arr);
        return search_in_rotated_sorted_array(arr,high,low,ansIdx);        
    } 
}

int find_num_rotations_in_rotated_sorted_array(vector<int> &arr)
{
    int n = arr.size();
    return search_in_rotated_sorted_array(arr, n-1, 0, 0);
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
    ans = find_num_rotations_in_rotated_sorted_array(arr1);

    cout << "Array has been rotated " << ans << " times."<< endl;      
}