#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Rotate array by one
/*
    Time complexity -> O(N)
    Space complexity -> O(1)
*/

void rotateArrayByOne(int arr[], int n)
{
    int temp = arr[0];
    for(int i=0;i<n-1;i++)
    {
        arr[i] = arr[i+1];
    }
    arr[n-1] = temp;
}

// Rotate array by K places
/*
    Time complexity -> O(k)+O(n-k)+O(k) -> O(n+k)
    Spcae complexity -> O(k)
*/

void rotateArrayByK(int arr[], int n, int k)
{
    k = k % n; // Rotating by n places gives back the original array

    int temp[k];
    for(int i=0; i<k; i++)
    {
        temp[i] = arr[i]; // Storing the first k elements in temp array
    }
    for(int i=k; i<n; i++)
    {
        arr[i-k] = arr[i]; // Shifting all other elements k places left
    }
    for(int i=n-k; i<n; i++)
    {
        arr[i] = temp[i-(n-k)]; // Filling up the last k places with the temp elements
    }
}

/*
    Optimized solution
    Time complexity -> O(k)+O(n-k)+O(n) -> O(2n)
    Space complexity -> O(1)
*/

void rotateArrayByKOptimized(int arr[], int n, int k)
{
    k = k % n;
    reverse(arr, arr+k);
    reverse(arr+k, arr+n);
    reverse(arr, arr+n);
}

// Move all zeroes to the end of array
/*
    Time complexity -> O(N)
    Space complexity -> O(1)
*/

void moveZeroesToEnd(int arr[], int n)
{
    int j =-1;
    for(int i = 0; i<n; i++)
    {
        if(arr[i] == 0)
        {
            j = i;
            break;
        }
    }
    if(j == -1)
    {
        return;
    }
    for(int i = j+1; i<n; i++)
    {
        if(arr[i] != 0)
        {
            swapInt(&arr[i], &arr[j]);
            j++;
        }
    }
} 

// Linear Search
/*
    Iterate through the array and return the index of the 
    num when you find it or return -1 if num is not present
*/

int linearSearch(int arr[], int n, int k)
{
    for(int i=0; i<n; i++)
    {
        if(arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}

// Union of two sorted arrays
/*
    Time complexity -> O(n1+n2)
    Space complexity -> O(n1+n2)
*/

vector<int> unionOfTwoSortedArrays(int a[], int b[], int n1, int n2)
{
    //int n1 = sizeof(a);
    //int n2 = sizeof(b);

    int i=0, j=0;

    vector<int> unionArr;

    while(i<n1 && j<n2)
    {
        if(a[i] <= b[j])
        {
            if(unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if(unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }

    while(j < n2)
    {
        if(unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    while(i < n1)
    {
        if(unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    return unionArr;
}

// Intersection of two sorted arrays
/*
    Time complexity -> O(n1 + n2) for worst case
    Space complexity -> O(1)
*/

vector<int> intersectionOfTwoSortedArrays(int a[], int b[], int n1, int n2)
{
    //int n1 = sizeof(a);
    //int n2 = sizeof(b);

    int i=0, j=0;

    vector<int> intersecArr;

    while(i<n1 && j<n2)
    {
        if(a[i] == b[j])
        {
            intersecArr.push_back(a[i]);
        
            i++;
            j++;
        }
        else
        {
            if(a[i] > b[j])
            {
                j++;
            }
            else
            {
                i++;
            }
        }
    }
    return intersecArr;
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

    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }

    //rotateArrayByOne(arr,n);
    //rotateArrayByK(arr,n,k);
    //rotateArrayByKOptimized(arr,n,k);
    //moveZeroesToEnd(arr,n);
    //int ans = linearSearch(arr,n,k);
        //cout << ans << endl;
    
    //vector<int> ans = unionOfTwoSortedArrays(arr1,arr2,n1,n2);
    vector<int> ans = intersectionOfTwoSortedArrays(arr1,arr2,n1,n2);

    for(auto it: ans)
    {
        cout << it << " ";
    }
}