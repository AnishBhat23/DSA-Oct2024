#include<bits/stdc++.h>
using namespace std;

/*
    Given an array/list of length ‘N’, where the array/list represents the boards 
    and each element of the given array/list represents the length of each board. 
    Some ‘K’ numbers of painters are available to paint these boards. Consider that 
    each unit of a board takes 1 unit of time to paint. You are supposed to return 
    the area of the minimum time to get this job done of painting all the ‘N’ boards 
    under the constraint that any painter will only paint the continuous sections of 
    boards.

    TC -> O(N * log(sum(arr)-max(arr)+1))
    SC -> O(1)
*/

int minimizeTime(vector<int> &arr, int toMin)
{
    int n = arr.size();

    int subArrayCount = 1;
    int sum = 0;
    for(int i=0; i<n; i++)
    {
        if(sum + arr[i] <= toMin)
        {
            sum += arr[i];
        }
        else
        {
            subArrayCount++;
            sum = arr[i];
        }
    }
    return subArrayCount;
}

int getPainterTime(vector<int> &arr, int m)
{
    int n = arr.size();
    
    if(m > n)
    {
        return -1;
    }

    int low = *max_element(arr.begin(), arr.end());
    int high = accumulate(arr.begin(), arr.end(), 0);

    while(low <= high)
    {
        int mid = (low+high)/2;
        int minimizedTime = minimizeTime(arr, mid);

        if(minimizedTime <= m)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{
    int N,m;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> m;  
    int ans;

    ans = getPainterTime(arr1, m);

    cout << "Minimized Painter Partition is : " << ans << endl;
}