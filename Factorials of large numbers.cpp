/*
Given an integer N, find its factorial.

Example 1:

Input: N = 5
Output: 120
Explanation : 5! = 1*2*3*4*5 = 120
Example 2:

Input: N = 10
Output: 3628800
Explanation :
10! = 1*2*3*4*5*6*7*8*9*10 = 3628800

Your Task:
You don't need to read input or print anything. Complete the function factorial() that takes integer N as input parameter and returns a list of integers denoting the digits that make up the factorial of N.


Expected Time Complexity : O(N2)
Expected Auxilliary Space : O(1)


Constraints:
1 ≤ N ≤ 1000
*/

class Solution {
public:
    vector<int> factorial(int N){

       vector<int> res;
       res.push_back(1);
       for(int x=2;x<=N;x++)
       {
           int car=0;
           for(int i=0;i<res.size();i++){
               int val=res[i]*x+car;
               res[i]=val%10;
               car=val/10;
           }
           while(car!=0)
           {
               res.push_back(car%10);
               car/=10;
           }
       }
       reverse(res.begin(),res.end());
       return res;
    }
