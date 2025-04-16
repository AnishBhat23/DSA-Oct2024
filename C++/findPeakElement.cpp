#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of length N. Peak element is defined as the element 
    greater than both of its neighbors. Formally, if 'arr[i]' is the 
    peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. 
    Find the index(0-based) of a peak element in the array. 
    If there are multiple peak numbers, return the index of any peak number.

    TC -> O(log2N)
    SC -> O(1)
*/

int findPeakElement(vector<int>& nums) 
{
   int n = nums.size();

   if(n == 1)
   {
       return 0;
   }

   if(nums[0] > nums[1])
   {
       return 0;
   }

   if(nums[n-1] > nums[n-2])
   {
       return n-1;
   }

   int low = 1, high = n-2;
   int mid = 0;

   while(low <= high)
   {
       mid = (low+high)/2;
       if((nums[mid-1] < nums[mid]) && (nums[mid] > nums[mid+1]))
       {
           return mid;
       }

       else if(nums[mid] > nums[mid-1])
       {
           low = mid + 1;
       }

       else if(nums[mid-1] > nums[mid])
       {
           high = mid - 1;
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
    ans = findPeakElement(arr1);

    cout << "Peak Element is at : " << ans << endl;

    
}