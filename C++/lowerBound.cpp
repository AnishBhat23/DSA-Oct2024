#include<bits/stdc++.h>
using namespace std;

/*
    Given a sorted array of N integers and an integer x, 
    write a program to find the lower bound of x.

    The lower bound algorithm finds the first or the smallest index 
    in a sorted array where the value at that index is greater than 
    or equal to a given key i.e. x.
*/

int lower_bound_search(vector<int> &arr, int high, int low, int target, int ans)
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
		return lower_bound_search(arr,high,low,target,ans);
	}
	else
	{
		low = mid+1;
		return lower_bound_search(arr,high,low,target,ans);
	}
}

int lowerBound(vector<int> &arr, int target)
{
    int ans = arr.size();
    return lower_bound_search(arr, arr.size(), 0, target, ans);
}


int upper_bound_search(vector<int> &arr, int high, int low, int target, int ans)
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
		return upper_bound_search(arr,high,low,target,ans);
	}
	else
	{
		low = mid+1;
		return upper_bound_search(arr,high,low,target,ans);
	}
}

int upperBound(vector<int> &arr, int target)
{
    int ans = arr.size();
    return upper_bound_search(arr, arr.size(), 0, target, ans);
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
    
    int ans_idx = lowerBound(arr1, k);
    int ans_idx_1 = upperBound(arr1, k);

    cout << "The lower bound is : " << ans_idx << endl;
    cout << "The upper bound is : " << ans_idx_1 << endl;
}