//
//
/*
Given two numbers, hour and minutes, return the smaller angle (in degrees) formed between the hour and the minute hand.

Answers within 10-5 of the actual value will be accepted as correct.

 

Example 1:


Input: hour = 12, minutes = 30
Output: 165
Example 2:


Input: hour = 3, minutes = 30
Output: 75
Example 3:


Input: hour = 3, minutes = 15
Output: 7.5
 

Constraints:

1 <= hour <= 12
0 <= minutes <= 59
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    double angleClock(int hour, int minutes) {
        double hourAngle;
        double minAngle;

        if (hour==12)
            hour=0;

        hourAngle=30*hour +0.5*minutes;
	    minAngle=6*minutes;

        double angleDiff;
        angleDiff=abs(hourAngle-minAngle);

        if (angleDiff>180)
            angleDiff=360-angleDiff;

        return angleDiff;    
    }
};

int main() {
    Solution sol;

    cout << left
         << setw(10) << "Hour"
         << setw(10) << "Minute"
         << setw(15) << "Angle"
         << '\n';

    cout << string(35, '-') << '\n';

    int tc = 1;

    for (int hour = 1; hour <= 12; hour++) {
        for (int minute = 0; minute < 60; minute++) {
            double ans = sol.angleClock(hour, minute);

            cout << setw(10) << hour
                 << setw(10) << minute
                 << setw(15) << fixed << setprecision(1) << ans
                 << '\n';

            tc++;
        }
    }

    cout << "\nTotal Test Cases Executed: " << tc - 1 << endl;

    return 0;
}