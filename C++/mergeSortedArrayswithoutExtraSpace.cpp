#include<bits/stdc++.h>
using namespace std;

/*
    Given two sorted arrays arr1[] and arr2[] of 
    sizes n and m in non-decreasing order. Merge 
    them in sorted order. Modify arr1 so that it 
    contains the first N elements and modify arr2 so 
    that it contains the last M elements.

    Brute Force -> Use a third array and compare each element and get the 
    final array. Then put back the array in the two original array. 

    TC -> O(2(n+m))
    SC -> O(n+m)

    Optimal approach 1 -> Using left and right pointers for both arrays and
    using the fact that they are sorted, we can swap the elements in the 2 arrays 
    and then sort the 2 arrays to get our final answer 

    TC -> O(min(n,m)) + O(nlogn) + O(mlogm)
    SC -> O(1)

    Optimal approach 2 -> This gap method is based on a sorting technique 
    called shell sort. Similar to optimal approach 1, in this approach, we will 
    use two pointers i.e. left and right, and swap the elements if the element 
    at the left pointer is greater than the element at the right pointer. 
    But the placing of the pointers will be based on the gap value calculated. 
    The formula to calculate the initial gap is the following:
    Initial gap = ceil((size of arr1[] + size of arr2[]) / 2)

    TC ->  O((n+m)*log(n+m))
    SC ->  O(1)

*/


void mergeTwoSortedArraysWithoutExtraSpace_brute(vector<long long> &a, vector<long long> &b){
	
	int n = a.size();
	int m = b.size();

	vector<long long> ans(n+m);

	int left = 0;
	int right = 0;
	int indx = 0;
	
	while(left < n && right < m)
	{
		if(a[left] <= b[right])
		{
			ans[indx] = a[left];
			left++;
			indx++;
		}
		else
		{
			ans[indx] = b[right];
			right++;
			indx++;
		}
	}
	while(left < n)
	{
		ans[indx++] = a[left++];
	}
	while(right < m)
	{
		ans[indx++] = b[right++];
	}

	for(int i = 0; i<n+m; i++)
	{
		if(i < n)
		{
			a[i] = ans[i];
		}
		else
		{
			b[i-n] = ans[i];
		}
	}

}

void swapIfGreater(vector<long long> &a, vector<long long> &b, int ind1, int ind2) {
    if (a[ind1] > b[ind2]) {
        swap(a[ind1], b[ind2]);
    }
}

void mergeTwoSortedArraysWithoutExtraSpace_optimal1(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();

	int left = n-1;
	int right = 0;

	while(left >= 0 && right < m)
	{
		if(a[left] >= b[right])
		{
			swap(a[left],b[right]);
			left--; right++;
		}
		else
		{
			break;
		}
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

}

void mergeTwoSortedArraysWithoutExtraSpace_optimal2(vector<long long> &a, vector<long long> &b){
	// Write your code here.
	int n = a.size();
	int m = b.size();
	int len = n + m;

    // Initial gap:
    int gap = (len / 2) + (len % 2);

    while (gap > 0) {
        // Place 2 pointers:
        int left = 0;
        int right = left + gap;
        while (right < len) {
            // case 1: left in arr1[]
            //and right in arr2[]:
            if (left < n && right >= n) {
                swapIfGreater(a, b, left, right - n);
            }
            // case 2: both pointers in arr2[]:
            else if (left >= n) {
                swapIfGreater(b, b, left - n, right - n);
            }
            // case 3: both pointers in arr1[]:
            else {
                swapIfGreater(a, a, left, right);
            }
            left++, right++;
        }
        // break if iteration gap=1 is completed:
        if (gap == 1) break;

        // Otherwise, calculate new gap:
        gap = (gap / 2) + (gap % 2);
    }

}

int main()
{
    int len1,len2,k;

    cin >> len1;
    cin >> len2;
    vector<long long> arr1;
    vector<long long> arr2;
    for(int i=0;i<len1;++i) 
    { 
        long long value; 
		cin >> value;  
		arr1.push_back(value); 
	}
    
    for(int i=0;i<len2;++i) 
    { 
        long long value; 
		cin >> value;  
		arr2.push_back(value); 
	}

    mergeTwoSortedArraysWithoutExtraSpace_brute(arr1,arr2);

    for (auto it : arr1) 
    {
        cout << it << " ";   
    }   

    cout << endl;

    for (auto it : arr2) 
    {
        cout << it << " ";   
    } 
    
}