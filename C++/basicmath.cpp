// Extract digits from a number

/*
    N is the given number
    while(N>0)
    {
        lastDigit = N%10
        digitCount++
        N=N/10
    }

    // to count digits
    cnt = (int)log10(n) + 1;

    // Time complexity = O(log10(N)) where N is the input number
    // if division is happening by 5, TC = O(log5(n))
*/

// Reversing a number

/*
    N is given number
    revN = 0
    while(N > 0)
    {
        lastDigit = N%10
        N = N/10
        revN = (revN*10)+lastDigit
    }
*/

// Check Palindrome

/*
    N is given number
    originNum = N
    revN = 0
    while(N > 0)
    {
        lastDigit = N%10
        N = N/10
        revN = (revN*10)+lastDigit
    }
    if(revN == originNum)
    {
        return true
    }
    else
    {
        return false
    }

*/


// Armstrong numbers

/*
    N = 371 = pow(3,3) + pow(7,3) + pow(1,3)
    or
    N = 1634 = pow(1,3) + pow(6,3) + pow(3,3) + pow(4,3)

    sum = 0
    originNum = N
    while(N > 0)
    {
        lastDigit = N%10
        sum = sum + pow(lastDigit,3)
        N = N/10 
    }

    if(sum == originNum)
        return true
    else
        return false


*/


// Print all divisors

/*
    N is the given number
    
    for(i=1;i*i<=n;i++)
    {
        if(N%i == 0)
        {
            print i
            if(n/i != 1)
                print (n/i)      
        }
    }

    O(sqrt(n)) time complexity;

*/

// Prime numbers

/*
    A number which has exactly 2 factors, 1 and the number itself
    N is the given number

    count = 0

    for(i=1; i*i<=N; i++)
    {
        if(N%i == 0)
        {
            count++
            if(n/i != 1)
                count++
        }
    }

    if(count == 2)
        true
    else
        false

    time complexity -> O(N) // Brute Force approach
                    -> O(sqrt(N)) //square root approach

*/


// GCD or HCF

/*
    Greatest common divisor OR Highest Common Factor

    for(i=1; i<=min(n1,n2); i++)
    {
        if(n1%i==0 && n2%i==0)
        {
            gcd = i;
        }
    }

    OR

    for(i=min(n1,n2); i>=1; i--)
    {
        if(n1%i==0 && n2%i==0)
        {
            gcd = i;
            break;
        }
    }

    time complexity -> O(min(n1,n2)) // Brute force approach
*/


// GCD or HCF Euclidean Algorithm

/*
    gcd(n1,n2) = gcd(n1-n2,n2) where n1>n2

    or 

    gcd(n1,n2) = gcd(n1%n2,n2) while n1>n2

    by this,

    while(a > 0 && b > 0)
    {
        if(a>b)
            a = a%b;
        else
            b = b%a;
    }
    if(a == 0)
        gcd = b
    else
        gcd = a


    time complexity -> O(log(min(a,b)))

*/