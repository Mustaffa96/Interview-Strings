/*
Given a string of lowercase alphabets and a number k, the task is to find the minimum value of the string after removal of ‘k’ characters. 
The value of a string is defined as the sum of squares of the count of each distinct character.
For example consider the string “geeks”, here frequencies of characters are g -> 1, e -> 2, k -> 1, s -> 1 and value of the string is 12 + 22 + 12 + 12 = 7
 

Example 1:

Input: S = "abccc", K = 1
Output: 6
Explanation: Remove one 'c', then frequency
will be a -> 1, b -> 1, c -> 2.
12 + 12 + 22 = 6
â€‹Example 2:

Input: S = "aaab", K = 2
Output: 2
Explanation: Remove 2 'a's, then frequency
will be a -> 1, b -> 1.
12 + 12 = 2
Your Task:  
You don't need to read input or print anything. Your task is to complete the function minValue() which takes the string s as inputs and returns the answer.

Expected Time Complexity: O(K*log(|S|))
Expected Auxiliary Space: O(constant)

Constraints:
1 ≤ K, |S| ≤ 104
*/

class Solution{
public:	
	int minValue(string S, int K)
	{
	    int arr[26]={0};
	    int sum=0;
	    if(K>S.length()){
	        return 0;
	    }
	    for(int i=0; i<S.length(); i++){
	        arr[S.at(i)-'a']++;
	    }
	    int i=0;
	    int index=0;
	    while(K!=0){
	        int maxx=-1;
	        for(int i=0; i<26; i++){
	            if(arr[i]>maxx){
	                maxx=arr[i];
	                index=i;
	            }
	        }
	        arr[index]-=1;
	        K--;
	    }
	    for(int i=0; i<26; i++){
	        arr[i]=arr[i]*arr[i];
	        sum+=arr[i];
	    }
	    return sum;
	}
