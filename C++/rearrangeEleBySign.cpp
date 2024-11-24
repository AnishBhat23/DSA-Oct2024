#include<bits/stdc++.h>
using namespace std;

/*
    An array of size N has N/2 negative and 
    N/2 positive numbers. Arrange the numbers
    such that there are alternate postitive and
    negative numbers with the original order
    maintained

    Brute force approach -> 
        Maintain 2 lists for positive and negative
        elements.
        Iterate through the input array and fill the
        two lists first, then replace the array with the 
        elements from the list.

        TC -> O(n + n/2)
        SC -> O(N)
    
    Optimal approach -> 
        We know that the resultant array must start 
        from a positive element so we initialize the 
        positive index as 0 and negative index as 1 
        and start traversing the array such that 
        whenever we see the first positive element, 
        it occupies the space at 0 and then posIndex 
        increases by 2 (alternate places).
        Similarly, when we encounter the first negative element, 
        it occupies the position at index 1, and then 
        each time we find a negative number, 
        we put it on the negIndex and it increments by 2.

        TC -> O(N)
        SC -> O(n)

*/

vector<int> rearrangeArrayElements(int a[], int n)
{
    vector<int> ansArr(n);
    int posIdx = 0, negIdx = 1;
    for(int i=0; i<n; i++)
    {
        if(a[i] > 0)
        {
            ansArr[posIdx] = a[i];
            posIdx+=2;
        }
        else
        {
            ansArr[negIdx] = a[i];
            negIdx+=2;
        }
    }
    return ansArr;
}

int* rearrangeArrayElementsV2(int a[], int n)
{
    vector<int> pos;
    vector<int> neg;
    for(int i=0; i<n; i++)
    {
        if(a[i] > 0)
        {
            pos.push_back(a[i]);
        }
        else
        {
            neg.push_back(a[i]);
        }
    }

    if(pos.size() > neg.size())
    {
        for(int i=0; i<neg.size(); i++)
        {
            a[i*2] = pos[i];
            a[i*2 + 1] = neg[i]; 
        }

        int idx = neg.size()*2;

        for(int i=neg.size(); i<pos.size(); i++)
        {
            a[idx] = pos[i];
            idx++;
        }
    }

    else
    {
        for(int i=0; i<pos.size(); i++)
        {
            a[i*2] = pos[i];
            a[i*2 + 1] = neg[i]; 
        }

        int idx = pos.size()*2;

        for(int i=pos.size(); i<neg.size(); i++)
        {
            a[idx] = neg[i];
            idx++;
        }
    }

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

    //vector<int> ans = rearrangeArrayElements(arr1,n1);
    int* ans = rearrangeArrayElementsV2(arr1,n1);
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