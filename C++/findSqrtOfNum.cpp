#include<bits/stdc++.h>
using namespace std;

/*
    You are given a positive integer n. 
    Your task is to find and return its square root. 
    If ‘n’ is not a perfect square, then return the floor value of 'sqrt(n)'.

    TC -> O(log2N)
    SC -> O(1)
*/

int findSqrtOfNum(int num)
{
    int test = num;
    int oddNum = 1;
    int count = 0;
    while(test>=oddNum)
    {      
        count++;
        test -= oddNum;
        oddNum += 2;
    }
    return count;
}

int findSqrtBinarySearch(int n)
{
    int low = 1, high = n;
    
    while(low <= high)
    {
        long long mid = (low+high)/2;
        long long val = mid*mid;
        if(val <= (long long)(n))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{
    int num;

    cin >> num;
    
    int ans;
    ans = findSqrtBinarySearch(num);

    cout << "Square Root is : " << ans << endl;    
}