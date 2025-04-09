#include<bits/stdc++.h>
using namespace std;

/*
    Given an integer array arr of size N, 
    sorted in ascending order (may contain duplicate values) 
    and a target value k. Now the array is 
    rotated at some pivot point unknown to you. 
    Return True if k is present and otherwise, return False.
    
    TC -> O(log2n)
    SC -> O(1)
    
*/

bool search_in_rotated_sorted_array(vector<int> &arr, int k)
{
    int n = arr.size(); // size of the array.
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = (low + high) / 2;

        //if mid points the target
        if (arr[mid] == k) return true;

        //Edge case:
        if (arr[low] == arr[mid] && arr[mid] == arr[high]) {
            low = low + 1;
            high = high - 1;
            continue;
        }

        //if left part is sorted:
        if (arr[low] <= arr[mid]) {
            if (arr[low] <= k && k <= arr[mid]) {
                //element exists:
                high = mid - 1;
            }
            else {
                //element does not exist:
                low = mid + 1;
            }
        }
        else { //if right part is sorted:
            if (arr[mid] <= k && k <= arr[high]) {
                //element exists:
                low = mid + 1;
            }
            else {
                //element does not exist:
                high = mid - 1;
            }
        }
    }
    return false;
}

bool find_x_in_rotated_sorted_array_dup(vector<int> &arr, int target)
{
    int n = arr.size();
    return search_in_rotated_sorted_array(arr, target);
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

    bool ans;
    ans = find_x_in_rotated_sorted_array_dup(arr1, k);

    
}