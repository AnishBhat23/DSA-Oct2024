#include<bits/stdc++.h>
using namespace std;

/*
    Given two numbers N and M, find the Nth root of M. 
    The nth root of a number M is defined as a number X 
    when raised to the power N equals M. If the 
    'nth root is not an integer, return -1.

    TC -> O(log2N)
    SC -> O(1)
*/

int power(int n, int m, int mid)
{
    long long ans = 1;
    for(int i=1; i<=n; i++)
    {
        ans *= mid;
        if(ans > m)
        {
            return 2;
        }
    }
    if(ans == m)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int findNthRootOfNum(int n, int m)
{
    int low = 1, high = m;

    while(low <= high)
    {
        int mid = (low+high)/2;
        int val = power(n,m,mid);
        if(val == 2)
        {
            high = mid - 1;
        }
        else if(val == 1)
        {
            return mid;
        }
        else
        {
            low = mid + 1;
        }
    }

    return -1;   
}

int main()
{
    int n, m;

    cin >> n;
    cin >> m;
    
    int ans;
    ans = findNthRootOfNum(n,m);

    cout << n << "th Root of " << m << " is : " << ans << endl;    
}