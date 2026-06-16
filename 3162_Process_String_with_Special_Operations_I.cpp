/*
You are given a string s consisting of lowercase English letters and the special characters: *, #, and %.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the final string result after processing all characters in s.

 

Example 1:

Input: s = "a#b%*"

Output: "ba"

Explanation:

i	s[i]	Operation	Current result
0	'a'	    Append      'a'	    "a"
1	'#'	    Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
Thus, the final result is "ba".

Example 2:

Input: s = "z*#"

Output: ""

Explanation:

i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
Thus, the final result is "".

 

Constraints:

1 <= s.length <= 20
s consists of only lowercase English letters and special characters *, #, and %.
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string processStr(string s) {
        string result="";
        for(char ch:s)
        {
            if(ch>='a' && ch<='z')
            {
                result+=ch;
            }
            else if( ch=='#' && !result.empty())
            {
                result+=result;
            }
            else if(ch=='%' && !result.empty())
            {
                reverse(result.begin(),result.end());
            }
            else if(ch=='*' && !result.empty())
            {
                result.pop_back();
            }
        }
        return result;
    }
};

int main() {
    Solution sol;

    vector<string> tests = {
        "a#b%*",
        "z*#",
        "abc",
        "a#",
        "ab#",
        "abc#",
        "a%",
        "ab%",
        "abc%",
        "a*",
        "ab*",
        "abc*",
        "*",
        "#",
        "%",
        "**",
        "##",
        "%%",
        "a##",
        "a%%",
        "a**",
        "ab#%",
        "ab%#",
        "ab*#",
        "ab#*",
        "a#b#",
        "a%b%",
        "abc###",
        "abc%%%",
        "abc***",
        "x#y#z#",
        "xyz%%%#",
        "a*b*c*",
        "abcd#%*",
        "mno#p%q*",
        "a#b#c#",
        "a%b%c%",
        "leetcode",
        "l#e#e#t#",
        "abc#def%",
        "a#b%c*d",
        "zzz###",
        "abcd%%%%",
        "qwerty",
        "q#w%e*r%t#",
        "aaaaaaaaaa",
        "a#a#a#a#",
        "abc*#%def",
        "p#q%r*s#",
        "abcdefghijklmnopqrst"
    };

    for (int i = 0; i < (int)tests.size(); i++) {
        cout << "TC " << (i + 1) << ":\n";
        cout << "Input : \"" << tests[i] << "\"\n";
        cout << "Output: \"" << sol.processStr(tests[i]) << "\"\n";
        cout << "-----------------------------\n";
    }

    return 0;
}