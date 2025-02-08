#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of N integers, 
    your task is to find unique quads 
    that add up to give a target value. 
    In short, you need to return an array 
    of all the unique quadruplets [arr[a], 
    arr[b], arr[c], arr[d]] such that their 
    sum is equal to a given target.

    Brute Force Approach -> 
        Iterate through all the quads and check if it matches the 
        target. 

        TC -> O(pow(n,4))
        SC -> O(2 *no of quadruplets)

    Better Approach -> 
        Use Hashing to reduce the time complexity

        TC -> O(pow(n,3)* log(M)) where M is the number of elements in the set
        SC -> O(2 * no of quads) + O(N)
*/

vector<vector<int>> fourSum_brute(vector<int>& nums, int target) {
    // Write your code here
    int n = nums.size();
    set<vector<int>> st;

    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n ; j++)
        {
            for(int k = j+1; k<n ; k++)
            {
                for(int l = k+1; l<n; l++)
                {
                    long long sum = nums[i] + nums[j];
                    sum += nums[k];
                    sum += nums[l];
                    if(sum == target)
                    {
                        vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                        sort(temp.begin(), temp.end());
                        st.insert(temp);
                    }
                }
            }
        }
    }

    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


vector<vector<int>> fourSum_better(vector<int>& nums, int target) {
    int n = nums.size();
    set<vector<int>> st;
    for(int i = 0; i<n; i++)
    {
        for(int j = i+1; j<n ;j++)
        {
            set<long long> hashmap;
            for(int k = j+1; k<n ;k++)
            {
                long long sum = (nums[i] + nums[j]);
                sum += (nums[k]); 
                long long fourth = target - sum;
                if(hashmap.find(fourth) != hashmap.end())
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], (int)fourth};
                    sort(temp.begin(), temp.end());
                    st.insert(temp);
                }
                hashmap.insert(nums[k]);
            }
        }
    }
    vector<vector<int>> ans(st.begin(), st.end());
    return ans;
}


vector<vector<int>> fourSum_optimal(vector<int>& nums, int target) {
    int n = nums.size();
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int i = 0; i<n; i++)
    {
        if(i>0 && nums[i] == nums[i-1]) continue;
        for(int j = i+1; j<n; j++)
        {
            if(j>i+1 && nums[j] == nums[j-1]) continue;
            int k = j+1;
            int l = n-1;
            while(k<l)
            {
                long long sum = nums[i] + nums[j];
                sum += nums[k];
                sum += nums[l];
                if(sum < target)
                {
                    k++;
                }
                else if(sum > target)
                {
                    l--;
                }
                else
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;
                    while(k<l && nums[k] == nums[k-1]) k++;
                    while(k<l && nums[l] == nums[l+1]) l--;
                }
            }
        }
    }
    return ans;
}

int main()
{
    int len, target;
    cin >> len;
    cin >> target;
    vector<int> arr1;
    int temp = 0;
    for(int i=0;i<len;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	} 
    vector<vector<int>> ans = fourSum_optimal(arr1, target);

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
        for (auto it1 : it)
        {
            cout << it1 << " ";
        }
        cout << endl;
    }

}