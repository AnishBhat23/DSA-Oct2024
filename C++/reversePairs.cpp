#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of numbers, you need to return the count of reverse pairs. 
    Reverse Pairs are those pairs where i<j and arr[i]>2*arr[j]

    Brute Force -> Generate all the pairs and count all the reverse pairs

    TC -> O(pow(n,2))
    SC -> O(1)

    Optimal -> Use merge sort to get the count of all reverse pairs

    TC -> O(logN * (n+n))
    SC -> O(n)
*/


int reversePairs_brute(vector<int> &arr)
{
    int n = arr.size();
    int rev_pair_cnt = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            if(arr[i] > 2*arr[j])
            {
                rev_pair_cnt++;
            }
        }
    }

    return rev_pair_cnt;
}


void merge(vector<int> &arr, int low, int mid, int high)
{
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
    //cout << endl;
}

int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int cnt = 0;
    int right = mid +1;

    for(int i = low; i<=mid; i++)
    {
        while(right <= high && arr[i] > 2*arr[right])
            right++;
        cnt += (right-(mid+1));
    }

    return cnt;
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
    cnt += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return cnt;
}

int reversePairs_optimal(vector<int> a)
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
    ans = reversePairs_optimal(arr1);

    cout << ans << " ";      
    
}