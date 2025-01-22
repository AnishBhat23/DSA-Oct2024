#include<bits/stdc++.h>
using namespace std;

/*
    Brute Force ->  
        Iterate through the entire array and check which 
        element appears more than floor(n/3) times.

        TC -> O(pow(n,2))
        SC -> O(1)

    Better Approach -> 
        Populate a hash map with the count of each element
        by iterating through the array once.

        TC -> O(n)*O(log n)
        SC -> O(N)
    
    Optimal Approach -> 
        Apply moore's voting algorithm to get the majority element
        occuring more than n/3 times

        TC -> O(N) + O(N)
        SC -> O(1)
*/


vector<int> majorityEle2(vector<int> nums)
{
    int cnt1 = 0, cnt2 = 0, chkCnt1 = 0, chkCnt2 = 0;
    int el1 = 0, el2 = 0;
    int n = nums.size();
    vector<int> ans;
    for(int i=0; i<n; i++)
    {
        if(cnt1 == 0 && nums[i] != el2)
        {
            cnt1 = 1;
            el1 = arr[i];
        }
        else if(cnt2 == 0 && nums[i] != el1)
        {
            cnt2 = 1;
            el2 = nums[i];
        }
        else if(nums[i] == el1)
        {
            cnt1++;
        }
        else if(nums[i] == el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }  
    }

    for(int i=0; i<n; i++)
    {
        if(nums[i] == el1)
        {
            chkCnt1++;
        }
        else if(nums[i] == el2)
        {
            chkCnt2++;
        }
    }

    if(chkCnt1 > (n/3))
    {
        ans.push_back(el1);
    }
    if(chkCnt2 > (n/3))
    {
        ans.push_back(el2);
    }
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
    
    vector<int> ans = majorityElement2(arr1);

    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */

    for(auto it: ans)
    {
        cout << it << " ";
    }

}