#include<bits/stdc++.h>
using namespace std;

int cnt = 0;
void rec1()
{
    if(cnt == 3) // This is the base condition
    {
        return;    
    }
    cout << cnt << endl;
    cnt++;
    rec1();
}

int main()
{
    rec1();
}

// Theory : https://takeuforward.org/recursion/introduction-to-recursion-understand-recursion-by-printing-something-n-times/