/*
Given two numbers N and K, change the Kth bit from left of the number N to '0' if it is  '1', else return the number N itself.

Example 1:

Input:
N = 13, K = 2
Output: 9
Explanation: Binary representation of 13 is
1101. The 2nd bit from left is 1, we make
it 0 and result is 1001 = 9 (decimal).
â€‹Example 2:

Input: 
N = 13, K = 6
Output: 13
Explanation: Binary representation of 13 is
11001. There's no 6th bit from left,
hence we return the number itself.

Your Task:
You don't need to read input or print anything. Your task is to complete the function replaceBit() which takes the integers N and K as inputs and returns the resultant number after the stated modifications.


Expected Time Complexity: O(LogN).
Expected Auxiliary Space: O(1).


Constraints:
1<=N<=106
*/

class Solution
{
  public:
    int replaceBit (int n, int k)
    {

       int limit = log2(n)+1;
       if(k>limit)
           return n;
       int i=limit-k;
       if(n&(1<<i))
           return n&(~(1<<i));
       else
           return n;
    }
};
