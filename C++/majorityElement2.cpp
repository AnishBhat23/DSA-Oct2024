#include<bits/stdc++.h>
using namespace std;

/*
    Brute Force ->  
        Iterate through the entire array and check which 
        element appears more than floor(n/3) times.

        TC -> O(pow(n,2))
        SC -> O(1)

    Better Approach -> 
        Populate a hash map with the count of each element
        by iterating through the array once.

        TC -> O(n)*O(log n)
        SC -> O(N)
    
    Optimal Approach -> 
         f
*/