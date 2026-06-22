//1189 Maximum_Number_of_Ballons
/*
Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 

Example 1:



Input: text = "nlaebolko"
Output: 1
Example 2:



Input: text = "loonbalxballpoon"
Output: 2
Example 3:

Input: text = "leetcode"
Output: 0
 

Constraints:

1 <= text.length <= 104
text consists of lower case English letters only.
 

Note: This question is the same as 2287: Rearrange Characters to Make Target String.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxNumberOfBalloons(string text) {
        
        vector<int> freq(26,0);
        for(auto ch:text)
            freq[ch-'a']++;

        /* Dumb ways of counting with while loop
        int numOfBallons=0;
        
        while(freq[0]>=1 && freq[1]>=1 && freq[11]>=2 && freq[13]>=1 && freq[14]>=2)
        {
           freq[0]--;
            freq[1]--;
            freq[11]-=2;
            freq[13]--;
            freq[14]-=2;
            numOfBallons++;
        }
        return numOfBallons;
        */
        return min({freq[0],freq[1],freq[11]/2,freq[13],freq[14]/2});
    }
};

int main() {

    Solution obj;

    vector<pair<string,int>> tests = {

        {"nlaebolko",1},
        {"loonbalxballpoon",2},
        {"leetcode",0},
        {"balloon",1},
        {"balloonballoon",2},
        {"balloonballoonballoon",3},
        {"b",0},
        {"a",0},
        {"l",0},
        {"o",0},
        {"n",0},

        {"balon",0},
        {"ballon",0},
        {"balloonn",1},
        {"bbaalllloooonn",2},
        {"balloo",0},
        {"balloonx",1},
        {"xballoon",1},
        {"xballoony",1},
        {"ballllllooooonnnn",1},

        {"bbbb",0},
        {"aaaa",0},
        {"llll",0},
        {"oooo",0},
        {"nnnn",0},

        {"balloonballoo",1},
        {"balloonballon",1},
        {"balloonballoonx",2},
        {"balloonballoonxx",2},
        {"balloonballoonxxx",2},

        {"balxloxon",0},
        {"ballxxoon",1},
        {"bballlloooonnn",2},
        {"bbbbaaalllllloooooonnnn",3},
        {"zzz",0},

        {"abcdefghijklmnopqrstuvwxyz",0},
        {"balloonabcdefghijklmnopqrstuvwxyz",1},
        {"abcballoonxyz",1},
        {"balloonballoonballoonballoon",4},
        {"loonbalxballpoonballoon",3},

        {"balloonballoonballoonballoonballoon",5},
        {"bbaalloon",1},
        {"bbaalllloooonn",2},
        {"nnoooollllbaa",1},
        {"nnoooollllbaaballoon",2},

        {"ballooooon",1},
        {"ballllooooonnn",2},
        {"bbbaaallllooooonnn",2},
        {"balloonballoonballoonballoonballoonballoon",6},
        {"",0} // optional, invalid per LC constraints but useful
    };

    for(int i=0;i<tests.size();i++)
    {
        string input = tests[i].first;
        int expected = tests[i].second;

        int actual = obj.maxNumberOfBalloons(input);

        cout << "TC #" << i+1 << "\n";
        cout << "Input    : \"" << input << "\"\n";
        cout << "Expected : " << expected << "\n";
        cout << "Actual   : " << actual << "\n";

        if(expected == actual)
            cout << "PASS\n";
        else
            cout << "FAIL\n";

        cout << "----------------------------------\n";
    }

    return 0;
}