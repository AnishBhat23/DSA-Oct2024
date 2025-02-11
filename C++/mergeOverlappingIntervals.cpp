#include<bits/stdc++.h>
using namespace std;


/*
    Given an array of intervals, merge all the overlapping intervals 
    and return an array of non-overlapping intervals

    Brute Force -> Sort the array to group the closer intervals
    Start from the first interval and keep accumulation as many 
    intervals as possible.

    if start(i) > end(ans), add the ans as one interval and start again 
    from the ith interval. 

    TC -> O(2N) + O(NlogN)
    SC -> O(N)

    Optimal Approach -> During one pass of the algo, accumulate all the overlapping
    intervals and also store the separate intervals in the ans array. 

    TC -> O(NlogN) + O(N)
    SC -> O(N)
*/


vector<vector<int>> mergeOverlappingIntervals_brute(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();

	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	for(int i=0; i<n; i++)
	{
		int start = arr[i][0];
		int end = arr[i][1];

		if(!(ans.empty()) && end <= ans.back()[1])
		{
			continue;
		}
		for(int j=i+1; j<n; j++)
		{
			if(arr[j][0] <= end)
			{
				end = max(end, arr[j][1]);
			}	
			else
			{
				break;
			}
		}
		ans.push_back({start,end});
	}

	return ans;	
}

vector<vector<int>> mergeOverlappingIntervals_optimal(vector<vector<int>> &arr){
	// Write your code here.
	int n = arr.size();

	sort(arr.begin(), arr.end());
	vector<vector<int>> ans;

	for(int i=0; i<n; i++)
	{
		if((ans.empty()) || arr[i][0] > ans.back()[1])
		{
			ans.push_back(arr[i]);
		}
		else
		{
			ans.back()[1] = max(ans.back()[1], arr[i][1]);
		}	
	}

	return ans;	
}

int main()
{
    int rows,cols,k;

    cin >> rows;
    cin >> cols;
    vector<vector<int>> arr1;
    int temp = 0;
    for(int i=0;i<rows;i++) 
    { 
		//Create a vector  
		vector<int> row; 
		for(int j=0;j<cols;j++)
        { 
			int value; 
			cin >> value; 
			row.push_back(value); 
		} 
		//Push the row in matrix 
		arr1.push_back(row); 
	} 

    vector<vector<int>> ansVect;
    ansVect = mergeOverlappingIntervals_optimal(arr1); 
       
    /*
    cin >> n2;
    int arr2[n2];
    for(int i=0; i<n2; i++)
    {
        cin >> arr2[i];
    }
    */
    
    for (auto it : ansVect) 
    {
        for (auto ele : it) 
        {
            cout << ele << " ";
        }
        cout << endl;
    }
}