#include<bits/stdc++.h>
using namespace std;

/*
You are given a string num, representing a large integer. Return the largest-valued odd integer (as a string) that is a non-empty substring of num, or an empty string "" if no odd integer exists.
A substring is a contiguous sequence of characters within a string.
*/

string largestOddNumber(string num) {
    int len = num.length();

    string ans = "";
    int ans_index_int = -1;

    if(int(num[len-1]) % 2 == 1)
    {
        return num;
    }
    else
    {
        int left = 0, right = 0;
        while(right < len)
        {
            if(num[right] % 2 == 0)
            {
                right++;
            }
            else
            {
                ans_index_int = max(ans_index_int, right);
                right++;
            }
        }
        if(ans_index_int == -1)
        {
            return ans;
        }
        else
        {
            ans = num.substr(left,(ans_index_int-left+1));
            return ans;
        }  
    }
}

int main()
{
    string arr;
    
    getline(cin,arr);
    
    string ans = largestOddNumber(arr);
    cout << "The answer string is : " << ans << endl;
}