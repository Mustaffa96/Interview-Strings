/*
Given two strings s1 and s2. Modify both the strings such that all the common characters of s1 and s2 are to be removed and the uncommon characters of s1 and s2 are to be concatenated.
Note: If all characters are removed print -1.

Example 1:

Input:
s1 = aacdb
s2 = gafd
Output: cbgf
Explanation: The common characters of s1
and s2 are: a, d. The uncommon characters
of s1 and s2 are c, b, g and f. Thus the
modified string with uncommon characters
concatenated is cbgf.
Example 2:

Input:
s1 = abcs
s2 = cxzca
Output: bsxz
Explanation: The common characters of s1
and s2 are: a,c. The uncommon characters
of s1 and s2 are b,s,x and z. Thus the
modified string with uncommon characters
concatenated is bsxz.
Your Task:
The task is to complete the function concatenatedString() which removes the common characters, concatenates, and returns the string. If all characters are removed then return -1.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(Number of distinct characters).
Note: N = |Length of Strings|

Constraints: 
1 <= |Length of Strings| <= 104
*/

class Solution
{
    public:
    //Function to remove common characters and concatenate two strings.
    string concatenatedString(string s1, string s2) 
    { 
        unordered_map<char,int> m;
        string r="";
        for(auto x: s1){
            m[x]=1;
        }
        for(auto x: s2){
            if(m[x]==0){
                r+=x;
            }
            else{
                m[x]=2;
            }

        }
         for(int i=s1.size()-1;i>=0;i--){
             char x=s1[i];
            if(m[x]==1){
                r=x+r;
            }
        }
        if(r.empty()){
            return "-1";
        }
        return r;
    }
