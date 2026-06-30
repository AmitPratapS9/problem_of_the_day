//8_Number_of_Substring_Containg_ABC_L1358
/*
Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 

Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 
Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 
Example 3:

Input: s = "abc"
Output: 1
 

Constraints:

3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        /* 
        //brute force pproach
        vector<string> v;
        for(int i=0;i<s.size();i++)
        {
            string text="";
            for(int j=i;j<s.size();j++)
            {
                text+=s[j];
                if(text.contains('a') && text.contains('b') && text.contains('c'))
                {
                    v.push_back(text);
                }
                else
                    continue;
            }
        }
        return v.size();
        */
        /*
        //counting approach also doesn't work and introduces O(n3) TC
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            string text="";
            for(int j=i;j<s.size();j++)
            {
                text+=s[j];
                if(text.contains('a') && text.contains('b') && text.contains('c'))
                {
                    cnt++;
                }
                else
                    continue;
            }
        }
        return cnt;
        */

        /*
        this introduces a O(n2) TC, still not good enough
        int cnt=0;
        for(int i=0;i<s.size();i++)
        {
            int a=0,b=0,c=0;
            for(int j=i;j<s.size();j++)
            {
                if(s[j]=='a')
                    a++;
                if(s[j]=='b')
                    b++;
                if(s[j]=='c')
                    c++;

                if(a && b && c)
                    cnt++;
            }
        }
        return cnt;
        */

        //Sliding window approach for a optimal O(n) TC
        int cnt=0;
        int lastseen[26]={-1,-1,-1};
        for(int i=0;i<s.size();i++)
        {
            lastseen[s[i]-'a']=i;
            if(lastseen[0]!=-1 && lastseen[1]!=-1 && lastseen[2]!=-1)
            {
                cnt=cnt+(1+min(min(lastseen[0],lastseen[1]),lastseen[2]));
            }
            

        }
        return cnt;
    }
};

int main() {
    Solution obj;

    vector<string> testCases = {
        // Basic
        "abc",
        "aaacb",
        "abcabc",
        "ababcbc",
        "cab",
        "cba",

        // Single character
        "a",
        "b",
        "c",

        // Two characters
        "ab",
        "ac",
        "bc",

        // Missing one character
        "aaaa",
        "bbbb",
        "cccc",
        "aabb",
        "bbcc",
        "aacc",

        // Exactly one valid substring
        "abca",
        "bcab",
        "cabc",

        // Repeated characters
        "aaabbbccc",
        "aaaabbbbcccc",
        "abcaaaa",
        "aaaabc",
        "bcaaaaa",

        // Alternating
        "abababaccc",
        "acbacbacb",
        "cbacbacba",

        // Longer examples
        "abcabcabc",
        "aaabcbcabc",
        "abccbaabc",

        // Edge cases
        "",
        "aaaaaaaaaaaa",
        "bbbbbbbbbbbb",
        "cccccccccccc",
        "abc",
        "acb",
        "bac",
        "bca",
        "cab",
        "cba",

        // Random
        "abbc",
        "bccaa",
        "aacbbc",
        "cbbaaac",
        "abacbc",
        "ccabbaa",
        "bbacccaaab",
        "aacccbbba",
        "cbabcabca",
        "accccbbaaa"
    };

    cout << left << setw(20) << "Input" << "Output\n";
    cout << string(30, '-') << '\n';

    for (const auto &s : testCases) {
        cout << left << setw(20) << ("\"" + s + "\"")
             << obj.numberOfSubstrings(s) << '\n';
    }

    return 0;
}