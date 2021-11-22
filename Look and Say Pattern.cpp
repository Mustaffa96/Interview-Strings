/*
Given an integer n. Return the nth row of the following look-and-say pattern.
1
11
21
1211
111221


Example 1:

Input:
n = 5
Output: 111221
Explanation: The 5th row of the given pattern
will be 111221.
Example 2:

Input:
n = 3
Output: 21
Explanation: The 3rd row of the given pattern
will be 21.

Your Task:  
You dont need to read input or print anything. Complete the function lookandsay() which takes integer n as input parameter and returns a string denoting the contents of the nth row of given pattern.


Expected Time Complexity: O(2n)
Expected Auxiliary Space: O(2n-1)  


Constraints:
1 ≤ n ≤ 30
*/

class Solution
{
  public:
    string helper(int n,string &s){
      if(n==1){
          return s;
      }
      string temp="";
      int count=1;
      for(int i=0;i<s.size();i++){
          if(i!=s.size()-1 && s[i]==s[i+1]){
              count++;
          }
          else{
              temp+=(to_string(count)+s[i]);
              count=1; //reset
          }
      }
      s=temp;
      return helper(n-1,s);
    }
    string lookandsay(int n) {
        string s="1";
        return helper(n,s);
    }   
