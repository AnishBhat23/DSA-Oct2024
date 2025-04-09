#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array arr of size N, 
    sorted in ascending order (with distinct values) 
    and a target value k. Now the array is rotated 
    at some pivot point unknown to you. 
    Find the index at which k is present and if k is not present return -1.

    Use the same low, mid and high pointers.
    Check which half of the array is sorted and
    then check if the element is within the half chosen;
    If not check in the other half. 

    TC -> O(log2(n))
    SC -> 


*/

int search_in_rotated_sorted_array(vector<int> &arr, int high, int low, int target)
{
    int mid = (high+low)/2;
    if(arr[mid] == target)
    {
        return mid;
    }
    if(low < high)
    {
        if(arr[low]<= arr[mid])
        {
            if(arr[low] <= target && target <= arr[mid])
            {
                high = mid-1;
                return search_in_rotated_sorted_array(arr,high,low,target);
            }
            else
            {
                low = mid+1;
                return search_in_rotated_sorted_array(arr,high,low,target);
            }
        }
        else
        {
            if(arr[mid] <= target && target <= arr[high])
            {
                low = mid+1;
                return search_in_rotated_sorted_array(arr,high,low,target);
            }
            else
            {
                high = mid-1;
                return search_in_rotated_sorted_array(arr,high,low,target);
            }
        }
    }
    else
    {
        return -1;
    }
}

int find_x_in_rotated_sorted_array(vector<int> &arr, int target)
{
    int n = arr.size();
    return search_in_rotated_sorted_array(arr, n-1, 0, target);
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
    cin >> k;

    int ans;
    ans = find_x_in_rotated_sorted_array(arr1, k);

    
}