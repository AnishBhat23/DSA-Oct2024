#include<bits/stdc++.h>
using namespace std;

// Largest Element in an array
/*
    Brute force approch would be to sort the array and return the last index. 
    But this will take min O(N*log2(N)) time complexity.

    Better approach is to itertate through all the elements and compare with
    the last largest element. Time complexity -> O(N)
*/

int largestEleInArray(int arr[], int n)
{
    int largest = arr[0];
    for(int i=1;i<n;i++)
    {
        if(arr[i] > largest)
        {
            largest = arr[i];
        }
    }
    return largest;
}

// Second Largest element in an array
/*
    Brute force would be to first sort the array and then 
    traverse back from the lasrgest element until we find the
    second largest element. This would take O(()N*log2(N))+N) 
    for the worst case. 

    Better approach would be first find the largest element
    by the itertaive method and then iterate again to find the 
    second largest element Time coplexity would be O(2N)
    
    Optimal approach is to store the largest and second largest 
    and replace each time by comparing whether the element is
    greater than largest or greater than second largest. 
    Time complexity -> O(N)

*/

int secondLargestEleInArray(int arr[], int n)
{
    int largest = arr[0], secondL = -1;
    for(int i=1;i<n;i++)
    {
        if(arr[i] > largest)
        {
            secondL = largest;    
            largest = arr[i];
        }
        if((arr[i] > secondL) && arr[i] < largest)
        {
            secondL = arr[i];
        }
    }
    return secondL;
}

int secondSmallestEleInArray(int arr[], int n)
{
    int smallest = arr[0], secondS = INT_MAX;
    for(int i=1;i<n;i++)
    {
        if(arr[i] < smallest)
        {
            secondS = smallest;    
            smallest = arr[i];
        }
        if((arr[i] < secondS) && arr[i] > smallest)
        {
            secondS = arr[i];
        }
    }
    return secondS;
}

// Check if the array is sorted

/*
    Loop through all the element of elements and check if element 
    n is always greater than or equal to element n-1

    Time complexity is O(N)
*/

bool isSorted(int arr[], int n)
{
    for(int i=1;i<n;i++)
    {
        if(!(arr[i] >= arr[i-1]))
        {
            return false;
        }
    }
    return true;
}

// Remove duplicates in place from sorted array
/*
    Brute force approach would be to add element of the array into 
    a set where the duplicate elements would be automatically ignored. 
    Then adding the elements back to the array and taking the count 
    would give the output. 
    Time complexity -> O((N*log2(N))+N)
    Space complexity -> O(N) as we are using set to store the unique 
                        elements. 
    
    Optimal approach would be to use 2 pointers(i,j) and check if 
    the element pointed to by i is not equal to element pointed to
    by j. Increment i each time a unique element is found.
    Time complexity -> O(N)
    Space complexity -> O(1)

*/

int removeDuplicates(int arr[], int n)
{   
    int i = 0;

    for(int j=1; j<n; j++)
    {
        if(arr[j] != arr[i])
        {
            arr[i+1] = arr[j];
            i++;
        }
    }
    return i+1;
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int largest = largestEleInArray(arr,n);
    cout << "Largest element is " << largest << endl;

    int secondLargest = secondLargestEleInArray(arr,n);
    cout << "Second Largest element is " << secondLargest << endl;

    cout << "Is the array sorted : " << (isSorted(arr,n)?"Yes":"No") << endl;

    int uniqueEleCount = removeDuplicates(arr,n);
    cout << "Number of unique elements is : " << uniqueEleCount << endl;

}