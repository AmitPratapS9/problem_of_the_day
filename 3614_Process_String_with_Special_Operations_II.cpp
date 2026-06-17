// https://leetcode.com/problems/find-kth-character-of-decompressed-string/
//3614_Process_String_with_Special_Operations_II
/*
You are given a string s consisting of lowercase English letters and the special characters: '*', '#', and '%'.

You are also given an integer k.

Build a new string result by processing s according to the following rules from left to right:

If the letter is a lowercase English letter append it to result.
A '*' removes the last character from result, if it exists.
A '#' duplicates the current result and appends it to itself.
A '%' reverses the current result.
Return the kth character of the final string result. If k is out of the bounds of result, return '.'.

 

Example 1:

Input: s = "a#b%*", k = 1

Output: "a"

Explanation:

i	s[i]	Operation	Current result
0	'a'	Append 'a'	"a"
1	'#'	Duplicate result	"aa"
2	'b'	Append 'b'	"aab"
3	'%'	Reverse result	"baa"
4	'*'	Remove the last character	"ba"
The final result is "ba". The character at index k = 1 is 'a'.

Example 2:

Input: s = "cd%#*#", k = 3

Output: "d"

Explanation:

i	s[i]	Operation	Current result
0	'c'	Append 'c'	"c"
1	'd'	Append 'd'	"cd"
2	'%'	Reverse result	"dc"
3	'#'	Duplicate result	"dcdc"
4	'*'	Remove the last character	"dcd"
5	'#'	Duplicate result	"dcddcd"
The final result is "dcddcd". The character at index k = 3 is 'd'.

Example 3:

Input: s = "z*#", k = 0

Output: "."

Explanation:

i	s[i]	Operation	Current result
0	'z'	Append 'z'	"z"
1	'*'	Remove the last character	""
2	'#'	Duplicate the string	""
The final result is "". Since index k = 0 is out of bounds, the output is '.'.

 

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters and special characters '*', '#', and '%'.
0 <= k <= 1015
The length of result after processing s will not exceed 1015.
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        const long long INF = (long long)4e18;
        vector<long long> len(n + 1, 0);

        // Compute lengths
        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                len[i + 1] = min(INF, len[i] + 1);
            }
            else if (ch == '*') {
                len[i + 1] = max(0LL, len[i] - 1);
            }
            else if (ch == '#') {
                len[i + 1] = min(INF, len[i] * 2);
            }
            else { // '%'
                len[i + 1] = len[i];
            }
        }

        if (k >= len[n])
            return '.';

        // Walk backwards
        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];

            if ('a' <= ch && ch <= 'z') {
                if (k == len[i]) {
                    return ch;
                }
            }
            else if (ch == '#') {
                if (len[i] > 0) {
                    k %= len[i];
                }
            }
            else if (ch == '%') {
                if (len[i] > 0) {
                    k = len[i] - 1 - k;
                }
            }
            // '*' needs special handling
            else if (ch == '*') {
                // Before '*' length was len[i]
                // After '*' length was len[i]-1
                // Since k is valid in the shorter string,
                // its position remains unchanged in the longer string.
            }
        }

        return '.';
    }
};

int main() {
    Solution sol;

    vector<pair<string, long long>> tests = {
        {"a",0},{"a",1},{"*",0},{"#",0},{"%",0},
        {"ab",0},{"ab",1},{"ab",2},
        {"a*",0},{"a*",1},
        {"a#",0},{"a#",1},{"a#",2},
        {"a%",0},{"a%",1},
        {"ab#",0},{"ab#",1},{"ab#",2},{"ab#",3},{"ab#",4},
        {"ab%",0},{"ab%",1},{"ab%",2},
        {"ab*",0},{"ab*",1},{"ab*",2},
        {"a#b",0},{"a#b",1},{"a#b",2},{"a#b",3},{"a#b",4},
        {"a#b%",0},{"a#b%",1},{"a#b%",2},{"a#b%",3},
        {"a#b%*",0},{"a#b%*",1},{"a#b%*",2}
    };

    auto brute = [](string s, long long k) -> char {
        string result;

        for (char ch : s) {
            if ('a' <= ch && ch <= 'z')
                result.push_back(ch);
            else if (ch == '*') {
                if (!result.empty())
                    result.pop_back();
            }
            else if (ch == '#')
                result += result;
            else if (ch == '%')
                reverse(result.begin(), result.end());

            if (result.size() > 100000)
                break;
        }

        return (k < result.size()) ? result[k] : '.';
    };

    int pass = 0;

    cout << left
         << setw(20) << "String"
         << setw(8) << "k"
         << setw(10) << "Expected"
         << setw(10) << "Actual"
         << "Result\n";

    cout << string(60, '-') << "\n";

    for (auto &[s, k] : tests) {
        char expected = brute(s, k);
        char actual = sol.processStr(s, k);

        bool ok = (expected == actual);

        cout << setw(20) << s
             << setw(8) << k
             << setw(10) << expected
             << setw(10) << actual
             << (ok ? "PASS" : "FAIL")
             << "\n";

        if (ok) pass++;
    }

    cout << "\nPassed " << pass
         << " / " << tests.size()
         << " test cases.\n";

    return 0;
}