#include<bits/stdc++.h>
using namespace std;

/*
    Print following pattern for input N
    n = 5
    * * * * *
    * * * * *
    * * * * * 
    * * * * * 
    * * * * * 
*/

void pattern1(int n)
{
    int r,c;
    for(r=0;r<n;r++)
    {
        for(c=0;c<n;c++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    * 
    * *
    * * *  
    * * * *  
    * * * * * 
*/

void pattern2(int n)
{
    int r,c;
    for(r=1;r<=n;r++)
    {
        for(c=0;c<r;c++)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    1 
    1 2
    1 2 3  
    1 2 3 4  
    1 2 3 4 5
*/

void pattern3(int n)
{
    int r,c;
    for(r=1;r<=n;r++)
    {
        for(c=1;c<=r;c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    1 
    2 2
    3 3 3  
    4 4 4 4  
    5 5 5 5 5
*/

void pattern4(int n)
{
    int r,c;
    for(r=1;r<=n;r++)
    {
        for(c=1;c<=r;c++)
        {
            cout << r << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    * * * * *
    * * * *
    * * *
    * *
    * 
*/

void pattern5(int n)
{
    int r,c;
    for(r=n;r>0;r--)
    {
        for(c=r;c>0;c--)
        {
            cout << "* ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    1 2 3 4 5
    1 2 3 4
    1 2 3
    1 2
    1
*/

void pattern6(int n)
{
    int r,c;
    for(r=n;r>0;r--)
    {
        for(c=1;c<=r;c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 3
        *
      * * *
    * * * * *
*/

void pattern7(int n)
{
    int r,c;
    for(r=0;r<n;r++)
    {
        for(c=0;c<(n-r-1);c++)
        {
            cout << " ";
        }
        for(c=0;c<(r*2)+1;c++)
        {
            cout << "*";
        }
        for(c=0;c<(n-r-1);c++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 3
    * * * * *
      * * *
        * 
*/

void pattern8(int n)
{
    int r,c;
    for(r=0;r<n;r++)
    {
        for(c=0;c<r;c++)
        {
            cout << " ";
        }
        for(c=0;c<((n-r-1)*2)+1;c++)
        {
            cout << "*";
        }
        for(c=0;c<r;c++)
        {
            cout << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 3
        *
      * * *
    * * * * *
    * * * * *
      * * *
        * 
*/

void pattern9(int n)
{
   pattern7(n);
   pattern8(n);
}

/*
    Print following pattern for input N
    n = 3
    * 
    * *
    * * *
    * *
    * 
*/

void pattern10(int n)
{
    int r,c;
    for(r=1;r<=(n*2)-1;r++)
    {
        int stars = r;
        if(r > n)
        {
            stars = n*2-r;
        }
        for(c=0;c<stars;c++)
        {
            cout << "*";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    1 
    0 1
    1 0 1  
    0 1 0 1  
    1 0 1 0 1
*/

void pattern11(int n)
{
    int r,c,bit=1;
    for(r=0;r<n;r++)
    {
        if(r%2 == 0)
        {
            bit = 1;
        }
        else
        {
            bit = 0;
        }
        for(c=0;c<=r;c++)
        {
            cout << bit << " ";
            bit = 1-bit; //Flipping a bit
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    1                 1
    1 2             2 1
    1 2 3         3 2 1
    1 2 3 4     4 3 2 1
    1 2 3 4 5 5 4 3 2 1
*/

void pattern12(int n)
{
    int r,c;
    for(r=1;r<=n;r++)
    {
        for(c=1;c<=r;c++)
        {
            cout << c << " ";
        }
        for(c=0;c<((n-r)*4);c++)
        {
            cout << " ";
        }
        for(c=r;c>=1;c--)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    1 
    2 3
    4 5 6  
    7 8 9 10  
    11 12 13 14 15
*/

void pattern13(int n)
{
    int r,c,num=1;
    for(r=1;r<=n;r++)
    {
        for(c=1;c<=r;c++)
        {
            cout << num << " ";
            num++;
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    A
    A B
    A B C
    A B C D
    A B C D E
*/

void pattern14(int n)
{
    int r;
    for(r=0;r<n;r++)
    {
        for(char c='A';c<='A'+r;c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    A B C D E
    A B C D
    A B C
    A B 
    A
*/

void pattern15(int n)
{
    int r;
    char c;
    for(r=n;r>0;r--)
    {
        for(c='A';c<'A'+r;c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    A
    B B
    C C C
    D D D D
    E E E E E
*/

void pattern16(int n)
{
    int r,c;
    char l;
    for(r=1;r<=n;r++)
    {
        l = 'A'+r-1;
        for(c=1;c<=r;c++)
        {
            cout << l << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 4
          A
        A B A
      A B C B A
    A B C D C B A
*/

void pattern17(int n)
{
    int r,c,br;
    char l = 'A';
    for(r=0;r<n;r++)
    {
        
        for(c=0;c<(n-r-1);c++)
        {
            cout << "  ";
        }
        l = 'A';
        br = ((r*2-1)/2)+1;
        for(c=0;c<((r*2)+1);c++)
        {
            cout << l << " ";
            if(c >= br)
            {
                l--;
            }
            else
            {
                l++; 
            }
        }
        for(c=0;c<(n-r-1);c++)
        {
            cout << "  ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 5
    E
    D E
    C D E
    B C D E
    A B C D E
*/
void pattern18(int n)
{
    int r;
    for(r=1;r<=n;r++)
    {
        for(char c='A'+n-r;c<'A'+n;c++)
        {
            cout << c << " ";
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 4
    * * * * * * * *
    * * *     * * *
    * *         * *
    *             *
    * *         * *
    * * *     * * *
    * * * * * * * *
*/

void pattern19(int n)
{
    //int r,c,
    int iniS = 0;
    for(int r=0;r<n;r++)
    {
        for(int c=0;c<(n-r);c++)
        {
            cout << "* ";
        }
        for(int c=0;c<iniS;c++)
        {
            cout << "  ";
        }
        for(int c=0;c<(n-r);c++)
        {
            cout << "* ";
        }
        iniS+=2;
        cout << endl;
    }
    iniS = 2*n-1;
    for(int r=1;r<=n;r++)
    {
        for(int c=0;c<r;c++)
        {
            cout << "* ";
        }
        for(int c=1;c<iniS;c++)
        {
            cout << "  ";
        }
        for(int c=0;c<r;c++)
        {
            cout << "* ";
        }
        iniS-=2;
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 6
    *          *
    **        **
    ***      ***
    ****    ****
    *****  *****
    ************
    *****  *****
    ****    ****
    ***      ***
    **        **
    *          *
*/

void pattern20(int n)
{
      // initialising the spaces.
      int spaces = 2*n-2;
      
      // Outer loop for printing row.
      for(int i = 1;i<=2*n-1;i++){
          
          // stars for first half
          int stars = i;
          
          // stars for the second half.
          if(i>n) stars = 2*n - i;
          
          //for printing the stars
          for(int j=1;j<=stars;j++){
              cout<<"* ";
          }
          
          //for printing the spaces
          for(int j = 1;j<=spaces;j++){
              cout<<"  ";
          }
          
          //for printing the stars
          for(int j = 1;j<=stars;j++){
              cout<<"* ";
          }
          
          // As soon as the stars for each iteration are printed, we move to the
          // next row and give a line break otherwise all stars
          // would get printed in 1 line.
          cout<<endl;
          if(i<n) spaces -=2;
          else spaces +=2;
      }
      
}

/*
    Print following pattern for input N
    n = 4
    * * * *
    *     *
    *     *
    * * * *
*/

void pattern21(int n)
{
    for(int r=0; r<n; r++)
    {
        for(int c=0; c<n; c++)
        {
            if(r == 0 || r == (n-1) || c == 0 || c == (n-1))
            {
                cout << "*";
            }
            else
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

/*
    Print following pattern for input N
    n = 3
    3 3 3 3 3 
    3 2 2 2 3
    3 2 1 2 3
    3 2 2 2 3
    3 3 3 3 3
*/

void pattern22(int n)
{
     // Outer loop for no. of rows
     for(int i=0;i<2*n-1;i++){
         
         // inner loop for no. of columns.
         for(int j=0;j<2*n-1;j++){
             
             // Initialising the top, down, left and right indices of a cell.
             int top = i;
             int left = j;
             int right = (2*n - 2) - j;
             int bottom = (2*n - 2) - i;
             
             // Min of 4 directions and then we subtract from n
             // because previously we would get a pattern whose border
             // has 0's, but we want with border N's and then decreasing inside.
             cout<<(n- min(min(top,bottom), min(left,right)))<<" ";
         }
         
         // As soon as the numbers for each iteration are printed, we move to the
         // next row and give a line break otherwise all numbers
         // would get printed in 1 line.
         cout<<endl;
     }
      
}

int main()
{
    int inp;
    cin >> inp;

    //pattern1(inp);
    //pattern2(inp);
    //pattern3(inp);
    //pattern4(inp);
    //pattern5(inp);
    //pattern6(inp);
    //pattern7(inp);
    //pattern8(inp);
    //pattern9(inp);
    //pattern10(inp);
    //pattern12(inp);
    //pattern13(inp);
    //pattern14(inp);
    //pattern15(inp);
    //pattern16(inp);
    //pattern17(inp);
    //pattern18(inp);
    //pattern19(inp);
    //pattern20(inp);
    //pattern21(inp);
    pattern22(inp);
    return 0;
}