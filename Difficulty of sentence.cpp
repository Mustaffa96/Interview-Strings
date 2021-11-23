/*
Given a sentence as a string S. Calculate difficulty of a given sentence.

Difficulty of sentence is defined as 5*(number of hard words) + 3*(number of easy words). A word in the given string is considered hard if it has 4 consecutive consonants or number of consonants are more than number of vowels. Else the word is easy.
Note: uppercase and lowercase characters are same.

Example

Input:
S = "Difficulty of sentence"
Output:
13
Explanation:
2 hard words + 1 easy word
Example

Input:
S = "I am good"
Output:
9
Explanation:
3 easy words
Your task:
You don't have to read input or print anything. Your task is to complete the functioin calcDiff() which takes the string S as input and returns the difficulty of the sentence.
 
Expected Time Complexity : O(len(s)
Expected Auxilliary Space : O(1)

Constraints:
1<= length( S ) <= 105
*/

// { Driver Code Starts
#include <iostream>
using namespace std;
int calcDiff(string str);
 
int main()
{
    int t;
    cin>>t;
    string x;
    getline(cin,x);
    while(t--)
    {
        string str;
        getline(cin,str);
         cout << calcDiff(str) << "\n";
    }
  
    return 0;
}// } Driver Code Ends

bool isVowel(char ch)
{
    return ( ch == 'a' || ch == 'e' ||
             ch == 'i' || ch == 'o' ||
             ch == 'u');
}

int calcDiff(string str)
{

    int count_vowels = 0, count_conso = 0;
    int hard_words = 0, easy_words = 0;
    int consec_conso = 0;
 
    // Start traversing the string
    for (int i = 0; i < str.length(); i++)
    {
        // Check if current character is vowel
        // or consonant
        if (str[i] != ' ' && isVowel(tolower(str[i])))
        {
            // Increment if vowel
            count_vowels++;
            consec_conso = 0;
        }
 
        // Increment counter for consonant
        // also maintain a separate counter for
        // counting consecutive consonants
        else if (str[i]!= ' ')
        {
            count_conso++;
            consec_conso++;
        }
 
        // If we get 4 consecutive consonants
        // then it is a hard word
        if (consec_conso == 4)
        {
            hard_words++;
 
            // Move to the next word
            while (i < str.length() && str[i]!= ' ')
                i++;
 
            // Reset all counts
            count_conso = 0;
            count_vowels = 0;
            consec_conso = 0;
        }
 
        else if ( i < str.length() &&
                  (str[i] == ' ' || i == str.length()-1))
        {
            // Increment hard_words, if no. of consonants are
            // higher than no. of vowels, otherwise increment
            // count_vowels
            count_conso > count_vowels ? hard_words++
                                       : easy_words++;
 
            // Reset all counts
            count_conso = 0;
            count_vowels = 0;
            consec_conso = 0;
        }
    }
 
    // Return difficulty of sentence
    return 5 * hard_words + 3 * easy_words;
    
    
}
