#include<bits/stdc++.h>
using namespace std;

/*
    You are given an array 'arr' of size 'n' which denotes the position of stalls.
    You are also given an integer 'k' which denotes the number of aggressive cows.
    You are given the task of assigning stalls to 'k' cows such that the minimum 
    distance between any two of them is the maximum possible.
    Find the maximum possible minimum distance.

    TC -> O(NlogN) + O(N * log(max(stalls[])-min(stalls[])))
    SC -> O(1)
*/

bool canIplaceCows(vector<int> &arr, int dist, int k)
{
    int n = arr.size();

    int cnt = arr[0];
    int cowsPlaced = 1;

    for(int i = 1; i<n; i++)
    {
        if(arr[i]-cnt >= dist)
        {
            cnt = arr[i];
            cowsPlaced++;
        }

        if(cowsPlaced >= k)
        {
            return true;
        }
    }
    return false;
}


int aggressiveCows(vector<int> &stalls, int k)
{
    //    Write your code here.
    sort(stalls.begin(), stalls.end());
    int n = stalls.size();
    int low = 1, high = (stalls[n-1]-stalls[0]);
    int ans;

    while(low <= high)
    {
        int mid = (low+high)/2;

        if(canIplaceCows(stalls, mid, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int N,k;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> k;  
    int ans;

    ans = aggressiveCows(arr1, k);

    cout << "Minimum Distance is : " << ans << endl;
}