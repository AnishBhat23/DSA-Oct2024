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
Given an array Arr[] of integers, 
rearrange the numbers of the given array 
into the lexicographically next greater permutation of numbers.

If such an arrangement is not possible, 
it must rearrange to the lowest possible order 
(i.e., sorted in ascending order).

Brute force approach ->
    Generate all the possible permutations of the given input array
    using recursion.
    TC -> for N input numbers, N! permutations are possible
          so TC = O(N!*N)

Better approach -> 
    Cpp has a STL next_permutation() to generate the same output

Optimal approach -> 
    Look for a longer prefix match
    find the breakpoint to get the longest prefix match possible
    breakpoint is where a[i] < a[i+1]
    replace a[i] with ele > a[i] but the smallest one. 
    then fill the remaining elements in ascending order.

    TC -> O(3N)
    SC -> O(N) or O(1)
*/

int* nextPermutation(int a[], int n)
{
    int breakPoint = -1;
    for(int i=n-2; i>=0; i--)
    {
        if(a[i] < a[i+1])
        {
            breakPoint = i;
            break;
        }
    }
    if(breakPoint == -1)
    {
        reverse(a,a+n);
        return a;
    }
    for(int i=n-1; i>breakPoint; i--)
    {
        if(a[i] > a[breakPoint])
        {
            swapInt(&a[i],&a[breakPoint]);
            break;
        }
    }
    reverse(a+breakPoint+1,a+n);
    return a;
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

    int* ans = nextPermutation(arr1,n1);

    for(int i=0; i<n1; i++)
    {
        cout << ans[i] << " ";
    }

    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    /*
    for(auto it: ans)
    {
        cout << it << " ";
    }
    */
}