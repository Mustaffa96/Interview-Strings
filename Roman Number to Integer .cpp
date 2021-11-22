/*
Given a string in roman no format (s)  your task is to convert it to an integer . Various symbols and their values are given below.
I 1
V 5
X 10
L 50
C 100
D 500
M 1000

Example 1:

Input:
s = V
Output: 5
Example 2:

Input:
s = III 
Output: 3
Your Task:
Complete the function romanToDecimal() which takes a string as input parameter and returns the equivalent decimal number. 

Expected Time Complexity: O(|S|), |S| = length of string S.
Expected Auxiliary Space: O(1)

Constraints:
1<=roman no range<=3999
*/

class Solution {
  public:
    int romanToDecimal(string &str) {
     unordered_map<char , int> _map;
       _map['I'] = 1;
       _map['V'] = 5;
       _map['X'] = 10;
       _map['L'] = 50;
       _map['C'] = 100;
       _map['D'] = 500;
       _map['M'] = 1000;
       
        if(str.size() == 1){
           return _map[str[0]];
       }
       
       int i = 0;
       int ans = 0;
       
       for(int i = 0 ; i< str.size() ; i++){
           if(str[i-1]  && _map[str[i]] > _map[str[i-1]]){
               ans += _map[str[i]] - 2 * _map[str[i-1]]; // subtracting 2 time to make it even
           }else{
               ans += _map[str[i]];
           }
       }

    return ans;
    }
