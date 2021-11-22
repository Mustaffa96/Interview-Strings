/*
Given two binary strings A and B consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.


Example 1:

Input:
A = "1101", B = "111"
Output: 10100
Explanation:
 1101
+ 111
10100
Example 2:

Input: 
A = "10", B = "01"
Output: 11
Explanation: 
  10
+ 01
  11

Your Task:
You don't need to read input or print anything. Your task is to complete the function addBinary() which takes 2 binary string A and B and returns a binary string denoting the addition of both the strings.


Expected Time Complexity: O(max(|A|, |B|)).
Expected Auxiliary Space: O(max(|A|, |B|)) (for output string).


Constraints:
1 ≤ |A|, |B| ≤ 106
*/

class Solution{
public:	
	string addBinary(string A, string B)
	{
    int l1=A.length();
    int l2=B.length();
    int carry=0;
    int res[l1+l2];
    for(int i=0;i<l1+l2;i++)
    {
        res[i]=0;
    }
    int i,j,ival,jval,sum;
    i=l1-1;
    j=l2-1;
   int  k=l1+l2-1;
    while(i>=0&&j>=0)
    {
        ival=A[i]-'0';
        jval=B[j]-'0';
        sum=ival+jval+carry;
        res[k]=sum%2;
        carry=sum/2;
        i--;
        k--;
        j--;
    }
    while(i>=0)
    {
        ival=A[i]-'0';
        sum=ival+carry;
        res[k]=sum%2;
        carry=sum/2;
        i--;
        k--;
    }
    while(j>=0)
    {
        jval=B[j]-'0';
        sum=jval+carry;
        res[k]=sum%2;
        carry=sum/2;
        j--;
        k--;
    }
    if(carry!=0)
    {
        res[k]=carry;
    }
    bool flg=false;
    string s;
    for(int i=0;i<l1+l2;i++)
    {
        if(res[i]==0&flg==false)
        {
            continue;
        }
        else{
            flg=true;
            s.push_back(res[i]+'0');
        }
    }
    if(s.empty())
    {
        return "0";
    }
    return s;
	}
