#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Recursive Bubble sort
/*
    Time complexity -> O(pow(N,2)) for worst case scenario
                    -> O(N) for best case scenario
    Space Complexity -> O(N)
*/


void recursiveBubbleSort(int arr[], int n)
{
    if(n == 1)
    {
        return;
    }
    int swapCntCheck = 0;
    for(int j=0; j<=n-2; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapInt(&arr[j],&arr[j+1]);
                swapCntCheck = 1;
            }
        }
    if(swapCntCheck == 0)
    {
        return;
    }

    recursiveBubbleSort(arr,n-1);
}

// Recursive Insertion sort
/*
    Time complexity -> O(pow(N,2)) for worst and average cases.
                    -> O(N) for best case 
    Space Complexity -> O(N) auxiliary stack space

*/

void recursiveInsertionSort(int arr[], int i, int n)
{       
    if(i == n)
    {
        return;
    }
    int j = i;
    while(j > 0 && (arr[j-1] > arr[j]))
    {
        swapInt(&arr[j], &arr[j-1]);
        j--;
    }

    recursiveInsertionSort(arr,i+1,n);
}

// Quick Sort
/*
    -> Pick a pivot element (any element of the given dataset)
    -> Place the pivot in its correct place in the sorted array
    -> Place the smaller element to the left of the pivot and the 
       larger element to the right of the pivot element 
    -> Take the left and right datasets of the pivot and 
       Repeat the above steps recursively until only one element remains

    Time complexity -> O(N*log2(N)) for best and average case, O(pow(N,2)) for worst case
    Space complexity -> O(1)
*/

int findPindex(int arr[], int low, int high)
{
    int pivot = arr[low];
    int i = low, j = high;

    while(i<j)
    {
        while(arr[i] >= pivot && i <= high-1)
        {
            i++;
        }
        while(arr[j] < pivot && j >= low+1)
        {
            j--;
        }
        if(i < j)
        {
            swapInt(&arr[i],&arr[j]);
        }
    }

    swapInt(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high)
{
    if(low < high)
    {
       int pIndex = findPindex(arr,low,high);
       quickSort(arr,low,pIndex-1);
       quickSort(arr,pIndex+1,high);
    }
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    //recursiveBubbleSort(arr,n);
    //recursiveInsertionSort(arr,0,n);

    quickSort(arr,0,n-1);

    for(auto it: arr)
    {
        cout << it << " ";
    }
}