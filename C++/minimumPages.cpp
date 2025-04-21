#include<bits/stdc++.h>
using namespace std;

/*
    Given an array ‘arr of integer numbers, ‘ar[i]’ represents the number of pages
    in the ‘i-th’ book. There are a ‘m’ number of students, and the task is to 
    allocate all the books to the students.
    Allocate books in such a way that:

    Each student gets at least one book.
    Each book should be allocated to only one student.
    Book allocation should be in a contiguous manner.
    You have to allocate the book to ‘m’ students such that the maximum number of 
    pages assigned to a student is minimum. If the allocation of books is not possible. return -1

    TC -> O(N * log(sum(arr)-max(arr)+1))
    SC -> O(1)
*/
int countStudent(vector<int> &arr, int pages)
{
    int n = arr.size();

    int studentCnt = 1;
    int pagesPerStudent = 0;
    for(int i=0; i<n; i++)
    {
        if(pagesPerStudent + arr[i] <= pages)
        {
            pagesPerStudent += arr[i];
        }
        else
        {
            studentCnt++;
            pagesPerStudent = arr[i];
        }
    }
    return studentCnt;
}

int minPagesforEachStudent(vector<int> &arr, int m)
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
        int studentCount = countStudent(arr, mid);

        if(studentCount <= m)
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

    ans = minPagesforEachStudent(arr1, m);

    cout << "Minimum pages is : " << ans << endl;
}