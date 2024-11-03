#include<bits/stdc++.h>
using namespace std;

// Program to input age and print if person is adult or not
// #define ADULT 18

// int main()
// {
//     int age;
//     cin >> age;

//     if(age >= ADULT)
//     {
//         cout << "You are an adult.";
//     }
//     else
//     {
//         cout << "You are not an adult!!";
//     }

//     return 0;
// }

/*
A school has the following grading system:
a. Below 25 - F
b. 25 to 44 - E
c. 45 to 49 - D
d. 50 to 59 - C
e. 60 to 79 - B
f. 80 to 100 - A
Ask user to enter the marks and print the corresponding grade
*/

// int main()
// {
//     int marks;
//     char grade='F';
    
//     cin >> marks;
    
//     if (marks < 25)
//     {
//         grade = 'F';
//     }
//     else if (marks >= 25 && marks <= 44)
//     {
//         grade = 'E';
//     }
//     else if (marks >= 45 && marks <= 49)
//     {
//         grade = 'D';
//     }
//     else if (marks >= 50 && marks <= 59)
//     {
//         grade = 'C';
//     }
//     else if (marks >= 60 && marks <= 79)
//     {
//         grade = 'B';
//     }
//     else if (marks >= 80 && marks <= 100)
//     {
//         grade = 'A';
//     }
//     else
//     {
//         cout << "Invalid marks!!";    
//         return 0;
//     }

//     cout << "Your grade is : " << grade;
//     return 0;
// }

/*
Take the age from the user and then decide accordingly
1. if age < 18,
   print -> not eligible for job
2. if age>= 18,
   print -> eligible for job
3. if age>= 55 and agc <= 57,
   print -> eligible for job, but retirement soon.
4. if age > 57
   print -> retirement time
*/

// int main()
// {
//     int age;
//     cin >> age;

//     if(age < 18)
//     {
//         cout << "Not eligible for job.";
//     }
//     else if(age <= 57)
//     {
//         cout << "Eligible for job";
//         if(age >= 55)
//         {
//             cout << ", but retirement soon.";
//         }
//     }
//     else
//     {
//         cout << "Retirement time.";
//     }

//     return 0;
// }


//Arrays and strings

// int main()
// {
//     string s = "AnishBhat";
//     int len = s.size();
//     s[len-1] = 'g';
//     cout << s;
//     return 0;
// }

