#include<bits/stdc++.h>
using namespace std;

int binary_search(vector<int> &arr, int high, int low, int target)
{
    if(low > high)
    {
        return -1;
    }
        int mid = (high+low)/2;
        if(arr[mid] == target)
        {
            return mid;
        }
        else if(arr[mid] > target)
        {
            high = mid-1;
            return binary_search(arr,high,low,target);
        }
        else
        {
            low = mid+1;
            return binary_search(arr,high,low,target);
        }
}

int find_x_in_sortedArray(vector<int> &arr, int target)
{
    int n = arr.size();
    int high = n-1;
    int low = 0;

    int mid = (high+low)/2;

    if(arr[mid] == target)
    {
        return mid;
    }
    else
    {
        return binary_search(arr,high,low,target);
    }
}

int main()
{
    int len1,k;

    cin >> len1;
    vector<int> arr1;
    for(int i=0;i<len1;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}
    cin >> k;
    
    int ans_idx = find_x_in_sortedArray(arr1, k);

    cout << "The target is at index: " << ans_idx;
}