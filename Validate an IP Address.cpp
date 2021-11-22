/*
Write a program to Validate an IPv4 Address. According to Wikipedia, IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots, e.g., 172.16.254.1 . The generalized form of an IPv4 address is (0-255).(0-255).(0-255).(0-255). Here we are considering numbers only from 0 to 255 and any additional leading zeroes will be considered invalid.

Your task is  to complete the function isValid which returns 1 if the ip address is valid else returns 0. The function takes a string s as its only argument .

Example 1:

Input:
ip = 222.111.111.111
Output: 1
Example 2:

Input:
ip = 5555..555
Output: 0
Explanation: 5555..555 is not a valid
ip address, as the middle two portions
are missing.
Your Task:
Complete the function isValid() which takes the string s as an input parameter and returns 1 if this is a valid ip address otherwise returns 0.

Expected Time Complexity: O(N), N = length of string.
Expected Auxiliary Space: O(1)

Constraints:
1<=length of string <=50

Note:The Input/Ouput format and Example given are used for system's internal purpose, and should be used by a user for Expected Output only. As it is a function problem, hence a user should not read any input from stdin/console. The task is to complete the function specified, and not to write the full code.
*/

class Solution {
    public:
        int isValid(string s) {
            string str="";
            int n = s.length();
            int i=0;
            int c=0;
            int num=0;
            for(i=0;i<n;i++)
            {
                if(s[i]=='.')
                {
                    c++;
                }
            }
            if(c!=3)
            {
                return 0;
            }
           for( i=0;i<n;i++)
           {
               if(isalpha(s[i]))
               {
                   return 0;
               }
                if(s[i]!='.')
               {
                   str+=s[i];
                   
               }
               else 
               {
                      
                      if(str.length()==0 || str.length()>3)
                      {
                          return 0;
                      }
                       if(stoi(str)>255 || stoi(str)<0)
                       {
                           return 0;
                       }
                       if(stoi(str)<256 || stoi(str)>=0)
                       {
                           str="";
                       }
                   
               }
               if(str[0]=='0')
               {
                   if(str.length()>1)
                   {
                       return 0;
                   }
               }
            
           }
           if(str.length()==0 || str.length()>3)
           {
               return 0;
           }
           if(stoi(str)>255 || stoi(str)<0)
           {
               return 0;
           }
          
           return 1;
        }
