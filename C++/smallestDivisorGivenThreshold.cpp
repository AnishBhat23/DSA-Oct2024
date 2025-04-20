#include<bits/stdc++.h>
using namespace std;

/*
    You are given an array of integers 'arr' and an integer 
    i.e. a threshold value 'limit'. Your task is to find the 
    smallest positive integer divisor, such that upon dividing 
    all the elements of the given array by it, the sum of the division's result 
    is less than or equal to the given threshold value.

    TC -> O(log(max(arr[]))*N)
    SC -> O(1)
*/
int checkThreshold(vector<int> &arr, int l, int div)
{
    int divsum = 0;
    for(int i=0; i<arr.size(); i++)
    {
        divsum += ceil((double)arr[i] / (double)div);
    }
    return divsum;
}


int minDivisor(vector<int> &arr, int l)
{
    int n = arr.size();

    int low = 1, high = *max_element(arr.begin(), arr.end());

    while(low <= high)
    {
        int mid = (high+low)/2;

        int divisorCheck = checkThreshold(arr,l,mid);
        if(divisorCheck <= l)
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
    int N,l;

    cin >> N;
    vector<int> arr1;
    for(int i=0;i<N;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    cin >> l;  
    int ans;

    ans = minDivisor(arr1, l);

    cout << "Minimum divisor is : " << ans << endl;
}