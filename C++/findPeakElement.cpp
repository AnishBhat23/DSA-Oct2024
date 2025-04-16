#include<bits/stdc++.h>
using namespace std;

/*
    Given an array of length N. Peak element is defined as the element 
    greater than both of its neighbors. Formally, if 'arr[i]' is the 
    peak element, 'arr[i - 1]' < 'arr[i]' and 'arr[i + 1]' < 'arr[i]'. 
    Find the index(0-based) of a peak element in the array. 
    If there are multiple peak numbers, return the index of any peak number.

    TC -> O(log2N)
    SC -> O(1)
*/