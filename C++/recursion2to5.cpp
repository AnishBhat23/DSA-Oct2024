#include<bits/stdc++.h>
using namespace std;

//print name n times using recursion
/*
    Time complexity is O(n)
    Space complexity is O(n)
*/

void printName(int i,int n)
{
    if(i == n)
    {
        return;
    }
    cout << "Anish" << endl;
    printName(i+1,n);
}


// Print linearly from 1 to N
void printNum(int i, int n)
{
    if(i > n)
    {
        return;
    }
    cout << i << endl;
    printNum(i+1,n);
}

// Print lineraly from N to 1
void printNumRev(int n)
{
    if(n < 1)
    {
        return;
    }
    cout << n << endl;
    printNumRev(n-1);
}

// Print from 1 to N by backtracing
void printNumBackTrack(int i, int n)
{
    if(i < 1)
    {
        return;
    }
    printNumBackTrack(i-1,n);
    cout << i << endl;
}

// Print from N to 1 using backtracking
void printNumRevBackTrack(int i,int n)
{
    if(i > n)
    {
        return;
    }
    printNumRevBackTrack(i+1,n);
    cout << i << endl;
}

// Given a number N, sum of first N natural numbers parameterized approach
void sumofFirstNparam(int sum,int n)
{
    if(n < 1)
    {
        cout << sum;
        return;
    }
    sumofFirstNparam(sum+n,n-1);
}

// Given a number N, sum of first N natural numbers returning sum approach
int sumofFirstNret(int n)
{
    if(n < 1)
    {
        return 0;
    }
    return n + sumofFirstNret(n-1);
}

// Factorial of a number : 5! = 5*4*3*2*1
void factorialRec(int n, int fact)
{
    if(n<1)
    {
        cout << fact;
        return;
    }
    factorialRec(n-1, fact*n);
}

// Factorial by returning value
long factorialRecRetVal(long n)
{
    if(n < 1)
    {
        return 1;
    }
    return n * factorialRecRetVal(n-1);
}

// Reverse an array

void reverseArray(int i,int* l,int n)
{
    if(i >= n/2)
    {
        return;
    }
    swap(l[i],l[n-i-1]);
    reverseArray(i+1,l,n);
}

// Check if a string is palindrome or not

bool checkPalindrome(int i, char*l, int n)
{
    if(i >= n/2)
    {
        return true;
    }
    if(l[i] != l[n-i-1])
    {
        return false;
    }
    else
    {
       checkPalindrome(i+1,l,n);
    }
}

// Fibonacci Number   0 1 1 2 3 5 8 13 21 34
/*
    Time complexity : O(pow(2,n)) where n is the fibonacci number approx
*/
int fibonacciNum(int n)
{
    if(n<=1)
    {
        return n;
    }
    return fibonacciNum(n-1) + fibonacciNum(n-2);
}

int main()
{
    long n=0,sum = 0;
    string in;
    cin >> n;

    //printName(0,n);
    //printNum(1,n);
    //printNumRev(n);
    //printNumBackTrack(n,n);
    //printNumRevBackTrack(1,n);
    //sumofFirstNparam(0,n);
    //sum = sumofFirstNret(n);
    //cout << sum;
    //factorialRec(n,1);
    //cout << factorialRecRetVal(n);
    
    /*
    int arr[n] = {0};
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    reverseArray(0,&arr[0],n);
    for(auto it:arr)
    {
        cout << it << endl;
    }
    */

    /*
    cin >> in;
    string inCp = in;
    cout << (checkPalindrome(0,&in[0],in.size())?"Palindrome!":"Not a Palindrome!");
    */

    cout << fibonacciNum(n);

    return 0;
}
