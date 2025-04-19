#include<bits/stdc++.h>
using namespace std;

/*
    You are given 'N’ roses and you are also given an array 'arr'  
    where 'arr[i]'  denotes that the 'ith' rose will bloom on the 'arr[i]th' day.
    You can only pick already bloomed roses that are adjacent to make a bouquet. 
    You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
    Find the minimum number of days required to make at least ‘m' bouquets each containing 'k' roses. 
    Return -1 if it is not possible.

    TC -> O(log2N)
    SC -> O(1)
*/

int possible(vector<int> &arr, int m, int k, int day)
{
    int cnt = 0, noOfB = 0;

    for(int i=0; i< arr.size(); i++)
    {
        if(arr[i] <= day)
        {
            cnt++;
        }
        else
        {
            noOfB += floor((double)cnt / (double)k);
            cnt = 0;
        }
    }
    noOfB += floor((double)cnt / (double)k);

    return noOfB;
}

int minDaysToMakeBouquet(vector<int> &arr, int m, int k)
{
    int n = arr.size();

    if((long long)n < (long long)m*k)
    {
        return -1;
    }

    int low = *min_element(arr.begin(), arr.end());
    int high = *max_element(arr.begin(), arr.end());

    while(low <= high)
    {
        int mid = (low+high)/2;
        int possibleB = possible(arr, m, k, mid);

        cout << "Low: " << low << " Mid: " << mid << " High: " << high << " PossibleB: " << possibleB << endl;
        
        if(possibleB < m)
        {
            low = mid + 1;
        }
        else if(possibleB >= m)
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int N,m,k;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> m;
    cin >> k;    
    int ans;

    ans = minDaysToMakeBouquet(arr1, m, k);

    cout << "Minimum number of days to make bouquets is : " << ans << endl;
}