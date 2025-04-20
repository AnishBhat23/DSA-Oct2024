#include<bits/stdc++.h>
using namespace std;

/*
    You are the owner of a Shipment company. You use conveyor belts 
    to ship packages from one port to another. The packages must be 
    shipped within 'd' days. The weights of the packages are given 
    in an array 'of weights'. The packages are loaded on the conveyor 
    belts every day in the same order as they appear in the array. 
    The loaded weights must not exceed the maximum weight capacity of the ship.
    Find out the least-weight capacity so that you can ship all the 
    packages within 'd' days.

    TC -> O((log(sum(a[])-max(a[]+1)*N))
    SC -> O(1)
*/

void getSumandLargestElement(vector<int> &arr, int *sum, int *max)
{
    int maxEle = INT_MIN, arrSum = 0;

    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] > maxEle)
        {
            maxEle = arr[i];
        }
        arrSum += arr[i];
    }

    *sum = arrSum;
    *max = maxEle;
}

int checkWeight(vector<int> &arr, int capacity)
{
    int n = arr.size();
    int dayCnt = 0;
    int weightCnt = 0;
    for(int i=0; i<n; i++)
    {   
        if(weightCnt + arr[i] > capacity)
        {
            dayCnt++;
            weightCnt = arr[i];
        }
        else
        {
            weightCnt+=arr[i];
        }
    }
    if(weightCnt > 0)
    {
        dayCnt++;
    }
    return dayCnt;
}

int shippingPackages(vector<int> &arr, int days)
{
    int n = arr.size();
    int low = 0, high = 0;
    getSumandLargestElement(arr, &high, &low);
    cout << "Low: " << low << " High: " << high << endl;

    while(low <= high)
    {
        int mid = (low+high)/2;

        int weightCap = checkWeight(arr, mid);
        if(weightCap > days)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}

int main()
{
    int N,d;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> d;  
    int ans;

    ans = shippingPackages(arr1, d);

    cout << "Minimum weight capacity is : " << ans << endl;
}