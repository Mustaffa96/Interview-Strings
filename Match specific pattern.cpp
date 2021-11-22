/*
Given a dictionary of words and a pattern. Every character in the pattern is uniquely mapped to a character in the dictionary. Find all such words in the dictionary that match the given pattern. 

Example 1:

Input:
N = 4
dict[] = {abb,abc,xyz,xyy}
pattern  = foo
Output: abb xyy
Explanation: xyy and abb have the same
character at index 1 and 2 like the
pattern.
Your Task:
You don't need to read input or print anything. Your task is to complete the function findMatchedWords() which takes an array of strings dict[] consisting of the words in the dictionary and a string, Pattern and returns an array of strings consisting of all the words in the dict[] that match the given Pattern in lexicographical order.

Expected Time Complexity: O(N*K) (where K is the length of the pattern).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 10
*/

string code(string s){
    int n=s.size();
    string ans="";
    unordered_map<char,int> mp;
    for(int i=0;i<n;i++){
        mp[s[i]]++;
        ans+=to_string(mp[s[i]]);
    }
    return ans;
}

vector<string> findMatchedWords(vector<string> dict,string pattern)
{
       vector<string> v;
       string pat=code(pattern);
       for(int i=0;i<dict.size();i++){
           if(pat==code(dict[i])){
               v.push_back(dict[i]);
           }
       }
       return v;
}
