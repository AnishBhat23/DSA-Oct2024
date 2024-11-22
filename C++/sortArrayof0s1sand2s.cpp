#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

/*
    Brute Force approach
        Use any of the sorting algo (MergeSort)
        TC -> O(NlogN)
        SC -> O(N)
    
    Better approach
        Keep a count of 0s, 1s and 2s
        Iterate once through the array updating the count

        Then populate the array based on the count of the variables.
        TC -> O(2N)
        SC -> O(1)
    
    Optimal approach
        Dutch National Flag Algorithm
        Use 3 pointers - low, mid and high
        [0......low-1] -> 0
        [low....mid-1] -> 1
        [mid.....high] -> all 0s,1s and 2s in unsorted order
        [high+1...n-1] -> 2

        Initially mid will point to start of array and high will point
        to end of array. 
        
        See code for further logic

        Time complexity -> O(N)
        Space complexity -> O(1)
*/

void sortArrayOf0s1sand2sBetterApp(int arr[], int n)
{
    int count0 = 0, count1 = 0, count2 = 0;
    int sortCnt = 0; 
    for(int i=0;i<n;i++)
    {
        if(arr[i] == 0)
        {
            count0++;
        }
        else if(arr[i] == 1)
        {
            count1++;
        }
        else
        {
            count2++;
        }
    }
    while(sortCnt < count0)
    {
        arr[sortCnt] = 0;
        sortCnt++;
    }
    while(sortCnt < count0+count1)
    {
        arr[sortCnt] = 1;
        sortCnt++;
    }
    while(sortCnt < count0+count1+count2)
    {
        arr[sortCnt] = 2;
        sortCnt++;
    }
}


void sortArrayOf0s1sand2sOptimalApp(int arr[], int n)
{
    int low = 0, mid = 0, high = (n-1);
    while(mid <= high)
    {
        if(arr[mid] == 0)
        {
            swapInt(&arr[low],&arr[mid]);
            low++;
            mid++;
        }
        else if(arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swapInt(&arr[mid],&arr[high]);
            high--;
        }
    }
}

int main()
{
    int n1,n2,k;

    cin >> n1;
    int arr1[n1];
    for(int i=0; i<n1; i++)
    {
        cin >> arr1[i];
    }
    
    //sortArrayOf0s1sand2sBetterApp(arr1, n1);
    sortArrayOf0s1sand2sOptimalApp(arr1, n1);

    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    
    for(auto it: arr1)
    {
        cout << it << " ";
    }
    
}