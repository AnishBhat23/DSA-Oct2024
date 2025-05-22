#include<bits/stdc++.h>
using namespace std;

vector<int> combineArrayElements(vector<int>&arr1, vector<int>&arr2, int n1, int n2)
{
    vector<int> arr3;

    int i=0,j=0;
    while(i<n1 && j<n2)
    {
        if(arr1[i] < arr2[j])
        {
            arr3.push_back(arr1[i++]);
        }
        else
        {
            arr3.push_back(arr2[j++]);
        }
    }

    while(i<n1)
    {
        arr3.push_back(arr1[i++]);
    }

    while(j<n2)
    {
        arr3.push_back(arr2[j++]);
    }

    return arr3;
}

double medianOfTwoSortedArrays_brute(vector<int>&arr1, vector<int>&arr2)
{
    int n1 = arr1.size();
    int n2 = arr2.size();
    int n = n1+n2;

    vector<int> arr3 =  combineArrayElements(arr1, arr2, n1, n2);

    if(n%2 == 1)
    {
        return arr3[n/2];
    }

    else
    {
        return (double)(((double)arr3[n/2] + (double)arr3[(n/2)-1])/2.0);
    }
}


int main()
{
    int N1,N2;

    cin >> N1;
    cin >> N2;
    vector<int> arr1;
    vector<int> arr2;
    for(int i=0;i<N1;++i) 
    { 
        int value; 
		cin >> value;  
		arr1.push_back(value); 
	}

    for(int i=0;i<N2;++i) 
    { 
        int value; 
		cin >> value;  
		arr2.push_back(value); 
	}
  
    double ans;

    ans = medianOfTwoSortedArrays_brute(arr1, arr2);

    cout << "The median of two sorted arrays is : " << ans << endl;
}