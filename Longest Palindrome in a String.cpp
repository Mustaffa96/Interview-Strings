/*
Given a string S, find the longest palindromic substring in S. Substring of string S: S[ i . . . . j ] where 0 ≤ i ≤ j < len(S). Palindrome string: A string which reads the same backwards. More formally, S is palindrome if reverse(S) = S. Incase of conflict, return the substring which occurs first ( with the least starting index).


Example 1:

Input:
S = "aaaabbaa"
Output: aabbaa
Explanation: The longest Palindromic
substring is "aabbaa".
Example 2:

Input: 
S = "abc"
Output: a
Explanation: "a", "b" and "c" are the 
longest palindromes with same length.
The result is the one with the least
starting index.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestPalin() which takes the string S as input and returns the longest palindromic substring of S.


Expected Time Complexity: O(|S|2).
Expected Auxiliary Space: O(1).


Constraints:
1 ≤ |S| ≤ 103
*/

class Solution {
  public:
    string longestPalin (string S) {
        string res="";
        int n=S.size();
        for(int i=0;i<n;i++){
            string ans="";
            int j=i;
            while(j<n&&S[i]==S[j]){
                ans.push_back(S[j]);
                j++;
            }
            int k=i-1;
            while(k>=0&&S[k]==S[j]){
                ans=S[k]+ans+S[j];
                k--;
                j++;
            }
            if(ans.size()>res.size()){
                res=ans;
            }
        }
        return res;
    }
