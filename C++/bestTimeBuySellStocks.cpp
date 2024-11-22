#include<bits/stdc++.h>
using namespace std;

/*
    Find the max profit to be made
    given the stock prices of
    every 'i'th day in an array

    Brute force approach -> 
        Use two loops to generate every
        transaction and compare the profits of
        each transcation to find the most profit. 
*/

int bestTimeBuySellStocks(int arr[], int n)
{
    int minPrice = INT_MAX, maxPrice = 0;
    for(int i=0; i<n; i++)
    {
        minPrice = min(minPrice, arr[i]);
        maxPrice = max(maxPrice,arr[i] - minPrice);
    }
    return maxPrice;
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

    int sum = 0;
    cin >> sum;
    int ans = bestTimeBuySellStocks(arr1,n1);
    cout << "Most profit to be made : " << ans << endl;

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