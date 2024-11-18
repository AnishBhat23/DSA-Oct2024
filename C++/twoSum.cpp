#include<bits/stdc++.h>
using namespace std;

void swapInt(int *a, int*b)
{
    int temp = 0;
    temp = *a;
    *a = *b;
    *b = temp;
}

// Two Sum problem
/*
    Find two elements in the given array such that
    their sum is equal to the sum given.

    Brute Force Approach -> 
        Take each element in the array and add
        every other element to check if the sum
        matches or not

        Time complexity -> about O(pow(n,2))
    
    Better solution -> 
        Use hashing : Store all elements in the hashmap 
        Take sum-i element, search 
        for the element in the hash map

        Time complexity -> O(log(n) * n)
        Space complexity -> O(n)
    
    Optimal Solution -> 
        Two pointer approach
        sort the array first
        use left and right pointer at both ends 
        of the array to get the indicies.

        Time complexity -> O(N) + O(NlogN)
        Space complexity -> O(1)/O(n)
*/

string twoSumProblem(int arr[], int n, int sum)
{
    map<int,int> mpp;
    for(int i = 0; i<n; i++)
    {
        if(mpp.find((sum-arr[i])) != mpp.end())
        {
            return "YES";
        }
        else
        {
            mpp[arr[i]] = i;
        }
    }
    return "NO";
}

string twoSumPointer(int arr[], int n, int sum)
{
    map<int,int> mpp;
    for(int i = 0; i<n; i++)
    {
        if(mpp.find((sum-arr[i])) != mpp.end())
        {
            return "YES";
        }
        else
        {
            mpp[arr[i]] = i;
        }
    }
    return "NO";
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

    long long sum = 0;
    cin >> sum;
    string ans = twoSumProblem(arr1,n1,sum);
    cout << "The given array has sum? : " << ans << endl;

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