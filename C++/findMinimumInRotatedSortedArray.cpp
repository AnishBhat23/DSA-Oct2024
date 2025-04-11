#include<bits/stdc++.h>
using namespace std;

int search_in_rotated_sorted_array(vector<int> &arr, int high, int low)
{
    int mid = (high+low)/2;

    if(arr[low] < arr[high])
    {
        return arr[low];
    }
    if(low < high)
    {
        if(arr[low] < arr[mid])
        {
            if(arr[mid] < arr[high])
            {
                high = mid-1;
                return search_in_rotated_sorted_array(arr,high,low);
            }
            else
            {
                low = mid+1;
                return search_in_rotated_sorted_array(arr,high,low);
            }
        }
        else
        {
            if(arr[mid] < arr[high])
            {
                low = mid+1;
                return search_in_rotated_sorted_array(arr,high,low);
            }
            else
            {
                high = mid-1;
                return search_in_rotated_sorted_array(arr,high,low);
            }
        }
    }

}

int find_min_in_rotated_sorted_array(vector<int> &arr)
{
    int n = arr.size();
    return search_in_rotated_sorted_array(arr, n-1, 0);
}