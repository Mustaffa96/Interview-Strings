/*
Given a String S, reverse the string without reversing its individual words. Words are separated by dots.

Example 1:

Input:
S = i.like.this.program.very.much
Output: much.very.program.this.like.i
Explanation: After reversing the whole
string(not individual words), the input
string becomes
much.very.program.this.like.i
Example 2:

Input:
S = pqr.mno
Output: mno.pqr
Explanation: After reversing the whole
string , the input string becomes
mno.pqr

Your Task:
You dont need to read input or print anything. Complete the function reverseWords() which takes string S as input parameter and returns a string containing the words in reversed order. Each word in the returning string should also be separated by '.' 


Expected Time Complexity: O(|S|)
Expected Auxiliary Space: O(|S|)


Constraints:
1 <= |S| <= 2000
*/

class Solution
{
    public:
    //Function to reverse words in a given string.
    string reverseWords(string S) 
    { 
        vector<string> ans;
        string temp="";
        string final="";
        for(int i=0;i<S.size();i++){
            if(S[i]=='.'){
                ans.push_back(temp);
                ans.push_back(".");
                temp="";
            }else{
                temp+=S[i];
            }
        }
        ans.push_back(temp);
        for(int i=ans.size()-1;i>=0;i--){
            final+=ans[i];
        }
        return final;
    } 
