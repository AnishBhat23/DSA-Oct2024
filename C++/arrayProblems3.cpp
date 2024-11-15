#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Find missing number in the array
/*
    Brute force approach-> 
        Use linear search for each element from 1 to N
        Time complexity -> O(pow(N,2))
        Space complexity -> O(1)
    
    Better Approach-> 
        Use Hashmaps to store the frequency of each element
        from 1 to N. 
        Return the element with frequency 0
        Time complexity -> O(2N)
        Space complexity -> O(N)
    
    Optimal approach 1 (Summation)->
        Use the summation formula - Sum = (n(n+1)) / 2 
        to get the sum of first N numbers.
        Compute the sum of all the elements in
        the given array. (Sum2)
        Ans = Sum - Sum2
        Time complexity -> O(N)
        Space complexity -> O(1)
        But datatype mismatch might 
        occur if input size > pow(10,5) 
    
    Optimal approach 2 (XOR method)->   
        Using property XOR(a,a) = 0 and XOR(0,a) = a
        XOR all elements from 1 to N to get XOR1
        XOR all the elements in the array to get XOR2
        XOR the value XOR1 and XOR2 to get the missing number
        Time complexity -> O(N)
        Space complexity -> O(1)
*/

int findMissingNumberInArray(int arr[], int n)
{
    int XOR1 = 0, XOR2 = 0;
    for(int i=0; i<n-1;i++)
    {
        XOR1 = XOR1 ^ i+1;
        XOR2 = XOR2 ^ arr[i];
    }
    XOR1 = XOR1 ^ n;

    return (XOR1^XOR2);
}

// Find Max consecutive ones in an array

/*
    Time complexity -> O(N)
    Space complexity -> O(1)
*/

int consecutiveOnesInArray(int arr[], int n)
{
    int oneCount = 0, countFlag = 0;
    for(int i=0; i<n; i++)
    {
        if(arr[i] == 1)
        {
            if(countFlag > oneCount)
            {
                oneCount = countFlag;
            }
            countFlag++;
        }
        else
        {
            if(countFlag > oneCount)
            {
                oneCount = countFlag;
            }
            countFlag = 0;
        }
    }
    return oneCount;
}

// Find the element which appears once in an array where each element appers twice

/*
    HashMap Approach -> ??
        Storing the frequency of each element 
        and printing the element with frequency one
        Time complexity -> O(N*logM)+O(M) where 
                           M is size of map -> (N/2)+1.
                           N is size of array.
        Space complexity -> O(M).
    
    XOR approach -> 
        Using property -> XOR(a) ^ XOR(a) = 0
                          XOR(a) ^ XOR(0) = a
        XOR all elements and the final answer
        will be the missing element. 
        Time complexity -> O(N) N is the elements 
        of array
        Space complexity -> O(1).
*/

int findSingleElement(int arr[], int n)
{
    int XOR = 0;
    for(int i=0; i<n; i++)
    {
        XOR = XOR ^ arr[i];
    }
    return XOR;
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

    //int ans = findMissingNumberInArray(arr1,n1);
    //cout << "Missing number : " << ans << endl;

    //int ans = consecutiveOnesInArray(arr1,n1);
    //cout << "Number of consecutive ones : " << ans << endl;

    int ans = findSingleElement(arr1,n1);
    cout << "Single element : " << ans << endl;

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