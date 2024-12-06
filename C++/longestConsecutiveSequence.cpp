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
    You are given an array of ‘N’ integers. 
    You need to find the length of the longest 
    sequence which contains the consecutive elements.

    Brute force approach ->     
        Pick up each element from the array and find the 
        next consecutive elements of that element. 
        When not found break and check the length, if greater 
        than max length replace with the max length

        TC -> O(pow(2,n))
        SC -> O(1)

    Better Approach -> 
        Sort 

*/




int main()
{
    int n1,n2,k;

    cin >> n1;
    int arr1[n1];
    for(int i=0; i<n1; i++)
    {
        cin >> arr1[i];
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