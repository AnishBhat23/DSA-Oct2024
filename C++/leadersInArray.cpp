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
    Given an array, print all the elements which are leaders. 
    A Leader is an element that is greater than all of the 
    elements on its right side in the array.

    Brute force approach -> 
        Iterate through all the elements and check if
        each element to the right of the seleted element 
        is a leader. 
        TC -> O(pow(n,2))
        SC -> O(n) for worst case to store the solution

    Optimal solution -> 
        Iterate through the array from the last element
        Compare each element with the max value. 
        If the element is greater than the max value, 
        copy the element to the ans array and update the max value

        TC -> O(N) + O(N log N)
        SC -> O(N)

*/

vector<int> leadersInArray(int a[], int n)
{
    int maxEle = INT_MIN;
    vector<int> ans;

    for(int i=n-1; i>=0; i--)
    {
        if(a[i] > maxEle)
        {
            ans.push_back(a[i]);
            maxEle = a[i];
        }        
    }
    reverse(ans.begin(), ans.end());
    return ans;
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

    vector<int> ans = leadersInArray(arr1,n1);

    for(auto it : ans)
    {
        cout << it << " ";
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