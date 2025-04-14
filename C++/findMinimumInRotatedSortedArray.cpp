#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array arr of size N, sorted in ascending order 
    (with distinct values). Now the array is rotated between 1 to N 
    times which is unknown. Find the minimum element in the array.
    
    TC -> O(log2n)
    SC -> O(1)
*/

int search_in_rotated_sorted_array(vector<int> &arr, int high, int low, int ans)
{
    if(low == high)
    {
        return min(arr[low],ans);
    }

    int mid = (high+low)/2;

    if(arr[low] <= arr[high])
    {
        return min(arr[low],ans);
    }

    if(arr[low] <= arr[mid])
    {
        low = mid+1;
        ans = min(ans, arr[low]);
        return search_in_rotated_sorted_array(arr,high,low,ans);
    }
    else
    {
        high = mid-1;
        ans = min(ans, arr[mid]);
        return search_in_rotated_sorted_array(arr,high,low,ans);        
    } 
}

int find_min_in_rotated_sorted_array(vector<int> &arr)
{
    int n = arr.size();
    return search_in_rotated_sorted_array(arr, n-1, 0,INT_MAX);
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
    ans = find_min_in_rotated_sorted_array(arr1);

    cout << "Minimum element : " << ans << endl;      
}