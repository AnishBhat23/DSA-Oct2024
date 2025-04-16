#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of N integers. Every number in the array except one appears twice. 
    Find the single number in the array.

    TC -> O(log2N)
    SC -> O(1)
*/


int find_single_ele_sorted_array(vector<int> &arr)
{
    int n = arr.size();

    if(n == 1)
    {
        return arr[0];
    }

    if(arr[0] != arr[1])
    {
        return arr[0];
    }
    
    if(arr[n-1] != arr[n-2])
    {
        return arr[n-1];
    }

    int low = 1;
    int high = n-2;

    int mid = (high+low)/2;

    while(low <= high)
    {
        mid = (high+low)/2;
        if(arr[mid] != arr[mid+1] && arr[mid] != arr[mid-1])
        {
            return arr[mid];
        }
        if(mid%2 != 0)
        {
            if(arr[mid] == arr[mid-1])
            {
                low = mid+1;
            }
            else if(arr[mid] == arr[mid+1])
            {
                high = mid-1;
            }
        }
        else
        {
            if(arr[mid] == arr[mid-1])
            {
                high = mid-1;
            }
            else if(arr[mid] == arr[mid+1])
            {
                low = mid+1;
            }
        }   
    }
    return -1;
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
    ans = find_single_ele_sorted_array(arr1);

    cout << "Single Element : " << ans << endl;      
}