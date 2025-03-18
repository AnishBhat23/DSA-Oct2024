#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of N integers, count the inversion of the array (using merge-sort).

    What is an inversion of an array? Definition: for all i & j < size of array, 
    if i < j then you have to find pair (A[i],A[j]) such that A[j] < A[i].

    Brute Force -> Iterate through the array to find all pairs such that a[i] > a[j]
                   and i < j.  
    TC -> O(pow(n,2))
    SC -> O(1)
    
    Optimal Solution -> Use the merge sort method and keep counting the inversions while
                        the merge
    TC -> O(N * log(N)) where N is the size of the array
    SC -> O(N) 
    

*/

int findInversions_brute(vector<int> a)
{
    int n = a.size();

    int inversion_count = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(a[i] > a[j])
            {
                inversion_count++;
            }
        }
    }

    return inversion_count;
}

int merge(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;

    vector<int> arrAns;
    int left = low;
    int right = mid+1;

    while(left<= mid && right <= high)
    {
        if(arr[left] <= arr[right])
        {
            arrAns.push_back(arr[left]);
            left++;
        }
        else
        {
            arrAns.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while(left <= mid)
    {
        arrAns.push_back(arr[left]);
        left++;
    }

    while(right <= high)
    {
        arrAns.push_back(arr[right]);
        right++;
    }

    for(int i=low; i<=high; i++)
    {
        arr[i] = arrAns[i-low];
        //cout << arr[i] << " ";
    }
    return cnt;
    //cout << endl;
}

int mergeSort(vector<int> &arr, int low, int high)
{
    // Divide
    int cnt = 0;
    if(low >= high)
    {
        return cnt;
    }
    int mid = (low + high)/2;
    cnt += mergeSort(arr, low, mid);
    cnt += mergeSort(arr, mid+1 ,high);

    cnt += merge(arr, low, mid, high);
    return cnt;
}

int findInversions_optimal(vector<int> a)
{
    int n = a.size();
    int ans = mergeSort(a,0,n-1); 
    return ans;
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
    ans = findInversions_optimal(arr1);

    cout << ans << " ";      
    
}