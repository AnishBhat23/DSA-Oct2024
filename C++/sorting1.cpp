#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort
/*
    Takes the minimum element to the front of the list.
    Time complexity
    Number of iterations is n + n-1 + n-2 ... + 1
    ie sum of first N natural numbers
    ie (pow(n,2) + n)/2
    Ignoring n/2
    We get O(pow(n,2)) for best, average and worst case
*/


void selectionSort(int arr[], int n)
{
    int min = 0;
    for(int i=0; i<(n-1); i++)
    {
        min = i;
        for(int j =i; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        swapInt(&arr[min], &arr[i]);
    }
}

// Bubble sort
/*
    Pushes the max element to the last by adjecent swaps.
    Time complexity is same as selection sort -> 
    O(pow(n,2)) for worst case scenario
    O(n) for best case scenario
*/

void bubbleSort(int arr[], int n)
{
    for(int i=n-1; i>0; i--)
    {
        int swapCntCheck = 0;
        for(int j=0; j<i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                swapInt(&arr[j],&arr[j+1]);
                swapCntCheck = 1;
            }
        }
        if(swapCntCheck == 0)
        {
            break;
        }
    }
}

// Insertion sort
/*
    Time complexity 
    Worst case -> O(pow(n,2))
    Avg case -> O(pow(n,2))
    Best case -> O(n)
*/

void insertionSort(int arr[], int n)
{
    for(int i=0; i<n; i++)
    {
        int j=i;
        while(j > 0 && (arr[j-1] > arr[j]))
        {
            swapInt(&arr[j], &arr[j-1]);
            j--;
        }
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

    // selectionSort(arr,n);
    // bubbleSort(arr, n);
    insertionSort(arr, n);

    for(auto it: arr)
    {
        cout << it << " ";
    }
}