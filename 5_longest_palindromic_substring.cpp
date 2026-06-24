//5_longest_palindromic_substring
/*
Given a string s, return the longest palindromic substring in s.

 

Example 1:

Input: s = "babad"
Output: "bab"
Explanation: "aba" is also a valid answer.
Example 2:

Input: s = "cbbd"
Output: "bb"
 

Constraints:

1 <= s.length <= 1000
s consist of only digits and English letters.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();

        int start = 0;
        int maxLen = 1;

        for (int i = 0; i < n; i++) {

            // Odd length palindrome
            int l = i;
            int r = i;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int currLen = r - l + 1;

                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = l;
                }

                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;

            while (l >= 0 && r < n && s[l] == s[r]) {
                int currLen = r - l + 1;

                if (currLen > maxLen) {
                    maxLen = currLen;
                    start = l;
                }

                l--;
                r++;
            }
        }

        return s.substr(start, maxLen);
    }
};

int main() {
    Solution obj;

    vector<string> tests = {
        "a",
        "aa",
        "ab",
        "aba",
        "abba",
        "abcba",
        "abccba",
        "babad",
        "cbbd",
        "racecar",
        "banana",
        "abcd",
        "aaaa",
        "aaaaa",
        "abcddcba",
        "forgeeksskeegfor",
        "aacabdkacaa",
        "abb",
        "bb",
        "ac",
        "abcbaq",
        "qabcba",
        "12321",
        "1221",
        "123454321",
        "abcdefgfedcba",
        "xyzzyx",
        "aabbaa",
        "abacdfgdcaba",
        "noon"
    };

    for (int i = 0; i < tests.size(); i++) {
        cout << "TC #" << i + 1 << "\n";
        cout << "Input  : " << tests[i] << "\n";
        cout << "Output : " << obj.longestPalindrome(tests[i]) << "\n";
        cout << "----------------------------------\n";
    }

    return 0;
}