#include<bits/stdc++.h>
using namespace std;

/*
    Given a sorted array of N integers, 
    write a program to find the index of 
    the last occurrence of the target key. 
    If the target is not found then return -1.

    Brute Approach -> Since array is sorted, iterate through the loop 
                      from the last element and print the index of the 
                      first occured element.
    TC -> O(n) in worst case
    SC -> O(1)
    
*/

pair<int, int> findLastOccurance_brute(vector<int> arr, int k)
{   
    int n = arr.size();
    int first_occur = -1;
    int last_occur = -1;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == k)
        {
            if(first_occur == -1)
                first_occur = i;
            last_occur = i;
        }
    }
    return {first_occur, last_occur};
}

int first_occurance_search(vector<int> &arr, int high, int low, int target, int ans)
{
	if(low > high)
	{
		return ans;
	}
	int mid = (high+low)/2;
	if(arr[mid] >= target)
	{
		ans = mid;
		high = mid-1;
		return first_occurance_search(arr,high,low,target,ans);
	}
	else
	{
		low = mid+1;
		return first_occurance_search(arr,high,low,target,ans);
	}
}

int last_occurance_search(vector<int> &arr, int high, int low, int target, int ans)
{
	if(low > high)
	{
		return ans;
	}
	int mid = (high+low)/2;
	if(arr[mid] > target)
	{
		ans = mid;
		high = mid-1;
		return last_occurance_search(arr,high,low,target,ans);
	}
	else
	{
		low = mid+1;
		return last_occurance_search(arr,high,low,target,ans);
	}
}

pair<int,int> findFirstandLastOccurance_optimal(vector<int> &arr, int target)
{
    int ans = arr.size();
    int last_occur = -1, first_occur = -1;
    if(arr.size() > 0)
    {
        last_occur = (last_occurance_search(nums, arr.size()-1, 0, target, ans)-1);
        first_occur = first_occurance_search(nums, arr.size()-1, 0, target, ans);
        
        if(first_occur >= arr.size() || arr[first_occur] != target)
        {
            return {-1 , -1};
        }
    }
    return {first_occur, last_occur};
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

    pair<int, int> ans;
    ans = findFirstandLastOccurance_optimal(arr1, k);

    cout << ans.first << " " << ans.second << " ";      
    
}