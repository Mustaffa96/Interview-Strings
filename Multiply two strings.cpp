/*
Given two numbers as stings s1 and s2. Calculate their Product.


Example 1:

Input:
s1 = "33"
s2 = "2"
Output:
66
Example 2:

Input:
s1 = "11"
s2 = "23"
Output:
253

Your Task:

You don't need to read input or print anything. Your task is to complete the function multiplyStrings() which takes two strings s1 and s2 as input and returns their product as a string.


Expected Time Complexity: O(n1* n2)
Expected Auxiliary Space: O(n1 + n2) ; where n1 and n2 are sizes of strings s1 and s2 respectively.


Constraints:
1 ≤ length of s1 and s2 ≤ 103
*/

class Solution{
  public:
    /*You are required to complete below function */
    string multiplyStrings(string s1, string s2) {
       int n = s1.size();
       int m = s2.size();
       if (s1 == "0" || s2 == "0")return "0";
       vector<int> v(n+m, 0);
       for (int i=n-1; i>=0; i--)
       {
           for (int j=m-1; j>=0; j--)
           {
               if (s1[i] != '-' && s2[j] != '-')
               {
                    v[i+j+1] += (s1[i] - '0') * (s2[j] - '0');
                    v[i+j] += v[i+j+1]/10;
                    v[i+j+1] %= 10;
                    // Basic multiplication using maths 
                    // Try to dry run this for more clearation 
               }
           }
       }
        string ans;
        if (s1[0] == '-')ans = '-';
        else if (s2[0] == '-')ans = '-';
        // If leading of any string is '-' makes the answer also negative
        
        if (s1[0] == '-' && s2[0] == '-')ans = ""; 
        // leading '-' in s1 and '-' in s2 make answer '+'
        
        int i=0;
       while (i < n+m && v[i]==0)i++;
       // Ignoring leading zeros
       
       while (i < n+m)ans += to_string(v[i++]); 
       // converting vector of int in string
       
       return ans;
    }
