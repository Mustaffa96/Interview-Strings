/*
Given two strings denoting non-negative numbers X and Y. Calculate the sum of X and Y.


Example 1:

Input:
X = "25", Y = "23"
Output:
48
Explanation:
The sum of 25 and 23 is 48.
Example 2:

Input:
X = "2500", Y = "23"
Output:
2523
Explanation:
The sum of 2500 and 23 is 2523.

Your Task:
Your task is to complete the function findSum() which takes two strings as inputs and returns the string without leading zeros. You do not need to take any input or print anything.


Expected Time Complexity: O(|X| + |Y|)
Expected Auxiliary Space: O(1)


Constraints:
1 <= |X|, |Y| <= 105
*/

typedef pair<char, char> pcc;
class Solution {
     pcc addition(char &c1, char &c2, char &carry) {
       int sum = (c1 - 48) + (c2 - 48) + (carry - 48);
       if (sum < 10) return {sum + 48, '0'};
       string temp = to_string(sum);
       return {temp[1], temp[0]};
   }

  public:
    string findSum(string X, string Y) {
       string ans, temp;
       int zeroes;
       if (X.size() > Y.size()) {
           zeroes = X.size() - Y.size();
           while (zeroes--) temp += '0';
           Y = temp + Y;
       } else if (Y.size() > X.size()) {
           zeroes = Y.size() - X.size();
           while (zeroes--) temp += '0';
           X = temp + X;
       }
       char sum, carry = '0';
       for (int i = X.size() - 1; i >= 0; i--) {
           pcc pair = addition(X[i], Y[i], carry);
           sum = pair.first, carry = pair.second;
           ans += sum;
       }
       if (carry != '0') ans += carry;
       reverse(ans.begin(), ans.end());
       if (ans[0] != '0') return ans;
       for (int i = 0; i < ans.size(); i++) {
           if (ans[i] != '0') {
               ans.erase(ans.begin(), ans.begin() + i);
               return ans;
           }
       }
       return "0";
    }
