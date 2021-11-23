/*
In a native language, the increasing order of priority of characters is a, b, c, d, e, f, g, h, i, j, k, l, m, n, ’ng’, o, p, q, r, s, t, u, v, w, x, y, z. You are given two strings s1 and s2 and your task is to compare them on the basis of the given priority order.

Note: Function must return 0 if both the strings are equal, 1 if s1 is greater than s2, and -1 if s1 is lesser than s2.

Example 1:

Input: s1 = "adding", s2 = "addio"
Output: -1
Explanation: 'o' has greater priority 
than 'ng'
Example 2:

Input: s1 = "abcng", s2 = "abcno"
Output: 1
Explanation: 'ng' has greater priority 
than 'n'
Your Task:  
You don't need to read input or print anything. Your task is to complete the function stringComparsion() which takes the two strings as input and returns the integer value.

Expected Time Complexity: O(|s1 + s2|)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ |s1|, |s2| ≤ 105
The string contains lower case English alphabets
*/

// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


int stringComparsion(string s1, string s2);


int main() 
{


   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s1, s2;
   		cin >> s1 >> s2;

   		
   		cout << stringComparsion(s1, s2) << "\n";
   	}

    return 0;
}
// } Driver Code Ends




int stringComparsion(string s1,string s2)
{
    if(s1==s2)
    return 0;
    int i=0;
    while(i<s1.size() && i<s2.size())
    {
        if(s1[i]==s2[i])
        {
            if(s1[i]=='n')
            {
                i++;
                if(s1[i]=='g' && s2[i]!='g')
                return 1;
                if(s2[i]=='g' && s1[i]!='g')
                return -1;
            }
            else
            i++;
        }
        else
        {
            if(s1[i]>s2[i])
            return 1;
            else
            return -1;
        }
    }
    if(i==s1.size())
    return -1;
    return 1;
}
