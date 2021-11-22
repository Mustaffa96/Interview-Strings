/*
Given an integer n, your task is to complete the function convertToRoman which prints the corresponding roman number of n. Various symbols and their values are given below.

I 1
V 5
X 10
L 50
C 100
D 500
M 1000

 

Example 1:

Input:
n = 5
Output: V
 

Example 2:

Input:
n = 3
Output: III
 

Your Task:
Complete the function convertToRoman() which takes an integer N as input parameter and returns the equivalent roman. 

 

Expected Time Complexity: O(log10N)
Expected Auxiliary Space: O(log10N * 10)

 

Constraints:
1<=n<=3999
*/

class Solution{
  public:
    string convertToRoman(int n) {

       string romans[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
       int num[]      = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
       string result = "";
       // int m = num;
       int i = 12;
       for(i=12; i>=0; i--)
       {
           while(n>=num[i])
           {
               result = result + romans[i];
               n = n - num[i];
           }
       }
       return result;
    }
};
