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
    recursiveInsertionSort(arr,0,n);

    for(auto it: arr)
    {
        cout << it << " ";
    }
}