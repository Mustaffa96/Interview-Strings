/*
Given a string S, find length of the longest substring with all distinct characters. 

Example 1:

Input:
S = "geeksforgeeks"
Output: 7
Explanation: "eksforg" is the longest 
substring with all distinct characters.
â€‹Example 2:

Input: 
S = "aaa"
Output: 1
Explanation: "a" is the longest substring 
with all distinct characters.

Your Task:
You don't need to read input or print anything. Your task is to complete the function longestSubstrDitinctChars() which takes the string S as input and returns the length of the longest substring with all distinct characters.


Expected Time Complexity: O(|S|).
Expected Auxiliary Space: O(K), where K is Constant.


Constraints:
1<=|S|<=105
*/

int longestSubstrDistinctChars (string S)
{
    int N = S.size();
    vector<int> lastIndex(256, -1);
    int i = 0;
    
    int res = 0;
    
    for(int j = 0; j < N; j++)
    {
        i = max(i, lastIndex[S[j]] + 1);
        
        res = max(res, j - i + 1);
        
        lastIndex[S[j]] = j;
    }
    
    return res;
}
