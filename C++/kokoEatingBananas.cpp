#include<bits/stdc++.h>
using namespace std;

/*
    A monkey is given ‘n’ piles of bananas, whereas the 'ith' pile has ‘a[i]’ bananas. 
    An integer ‘h’ is also given, which denotes the time (in hours) for all the bananas 
    to be eaten.
    Each hour, the monkey chooses a non-empty pile of bananas and eats ‘k’ bananas. 
    If the pile contains less than ‘k’ bananas, then the monkey consumes all the bananas 
    and won’t eat any more bananas in that hour.
    Find the minimum number of bananas ‘k’ to eat per hour so that the monkey can eat 
    all the bananas within ‘h’ hours.

    TC -> ()
    SC -> ()
*/

int calcTotHours(vector<int>&arr, int hourly)
{
    int totalHours = 0;
    for(int i = 0; i<arr.size(); i++)
    {
        totalHours += ceil(arr[i]/hourly);
    }
    return totalHours;
}


int kokoEatingBananas(vector<int>&arr, int n, int h)
{
    int low = 1, high = *max_element(arr.begin(), arr.end());

    while(low <= high)
    {
        int mid = (low+high)/2;
        int totalH = calcTotHours(arr, mid);
        if(totalH <= h)
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
    int len1,len2,h;

    cin >> len1;
    vector<int> arr1;
    for(int i=0;i<len1;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> h;    
    int ans;

    ans = kokoEatingBananas(arr1, len1, h);

    cout << "Minimum number of bananas per hour is : " << ans << endl;
}