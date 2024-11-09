#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// MergeSort
/*
    Divide and Merge
*/

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> arrAns;
    int left = low;
    int right = mid+1;

    while(low <= mid && right <= high)
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

void mergeSort(vector<int> &arr, int low, int high)
{
    // Divide
    if(low >= high)
    {
        return;
    }
    int mid = (low + high)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1 ,high);

    merge(arr, low, mid, high);
}

int main()
{
    int n,num=0;
    cin >> n;
    vector<int> arr = {5,83,85,84,1,8,67,4,78,16,25,49,2,8,17};
    
    /*
    for(int i=0; i<n; i++)
    {
        cin >> num;
        arr.push_back(num);
    }
    */

    mergeSort(arr,0,(n-1));
   
    for(auto it: arr)
    {
        cout << it << " ";
    }

    return 0;

}