/*
For given string ‘str’ of digits, find length of the longest substring of ‘str’, such that the length of the substring is 2k digits and sum of left k digits is equal to the sum of right k digits.
 

Input:

The first line of input contains an integer T denoting the number of test cases. The description of T test cases follows.
Each test case contains a string string of length N.

Output:

Print length of the longest substring of length 2k such that sum of left k elements is equal to right k elements and if there is no such substring print 0.


Constraints:

1 ≤ T ≤ 100
1 ≤ N ≤ 100

Example:

Input:
2
000000
1234123

Output:
6
4  
*/

#include <iostream>
using namespace std;
int maxlen(string s,int i,int j,int n)
{
    if(i==0||j==n-1)
    {
        if(s[i]==s[j])
        return 2;
        else
        return 0;
    }
    
    unsigned long long int s1=0,s2=0;
    int ans=0;
    while(i>=0 && j<n)
    {
        s1+=s[i];
        s2+=s[j];
        if(s1==s2)
        ans=j-i+1;
        
        i--;
        j++;
    }
    return ans;
}
void find()
{
    string s;
    cin>>s;
    int n=s.size();
    int i=0,j=1;
    int ans=0;
    for(int k=0;k<n-1;k++)
    {
        i=k;
        j=k+1;
        ans=max(ans,maxlen(s,i,j,n));
    }
cout<<ans<<endl;

}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	find();
	}
	return 0;
}
