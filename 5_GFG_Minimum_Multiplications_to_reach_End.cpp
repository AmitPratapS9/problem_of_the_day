//5_GFG_Minimum_Multiplications_to_reach_End : https://www.geeksforgeeks.org/problems/minimum-multiplications-to-reach-end/1
/*
Given two integers, start and end, along with an array of integers arr[]. In one operation, you can multiply the current value by any element from arr[], and then take the result modulo 1000 to obtain a new value.

Find the minimum steps in which end can be achieved starting from start. If it is not possible to reach end, then return -1.

Examples :

Input: arr[] = [2, 5, 7], start = 3, end = 30
Output: 2
Explanation:
Step 1: 3*2 = 6 % 1000 = 6 
Step 2: 6*5 = 30 % 1000 = 30
Input: arr[] = [3, 4, 65], start = 7, end = 175
Output: 4
Explanation:
Step 1: 7 * 3 = 21 % 1000 = 21  
Step 2: 21 * 3 = 63 % 1000 = 63  
Step 3: 63 * 65 = 4095 % 1000 = 95  
Step 4: 95 * 65 = 6175 % 1000 = 175 
Input: arr[] = [2, 4], start = 3, end = 5
Output: -1
Explanation: Starting from 3 and multiplying by 2 or 4 always produces even numbers after the first step. Since 5 is odd, it can never be reached.
Constraints:
1  ≤ arr.size()  ≤ 103
1  ≤ arr[i]  ≤ 103
0  ≤ start, end  < 103

*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(vector<int>& arr, int start, int end) {

        if(start == end)
            return 0;

        queue<pair<int,int>> q;
        q.push({start,0});

        vector<int> dist(1000,1e9);
        dist[start] = 0;

        int mod = 1000;

        while(!q.empty())
        {
            int node = q.front().first;
            int steps = q.front().second;
            q.pop();

            for(auto it : arr)
            {
                int num = (it * node) % mod;

                if(steps + 1 < dist[num])
                {
                    dist[num] = steps + 1;

                    if(num == end)
                        return dist[num];

                    q.push({num, dist[num]});
                }
            }
        }

        return -1;
    }
};

int main()
{
    Solution obj;

    vector<tuple<vector<int>,int,int>> tests;

    // ===== Fixed Edge Cases =====

    tests.push_back({{1},0,0});
    tests.push_back({{1},5,5});
    tests.push_back({{1},7,9});
    tests.push_back({{2},1,2});
    tests.push_back({{2},1,4});
    tests.push_back({{2},1,8});
    tests.push_back({{2},1,999});
    tests.push_back({{999},1,999});
    tests.push_back({{999},999,1});
    tests.push_back({{2,3,4},7,175});
    tests.push_back({{3,4,65},7,175});
    tests.push_back({{2,2,2},5,40});
    tests.push_back({{7},0,999});
    tests.push_back({{5},999,0});
    tests.push_back({{1,2,3},999,999});
    tests.push_back({{17,19,23},1,997});
    tests.push_back({{10},1,0});
    tests.push_back({{1000},1,0});
    tests.push_back({{999},0,0});
    tests.push_back({{1,999},999,999});

    // ===== More deterministic cases =====

    for(int i=1;i<=30;i++)
    {
        vector<int> arr;
        arr.push_back(i);
        tests.push_back({arr, i%1000, (i*i)%1000});
    }

    // ===== Random Cases =====

    srand(42);

    while(tests.size() < 150)
    {
        int n = rand()%10 + 1;

        vector<int> arr;

        for(int i=0;i<n;i++)
            arr.push_back(rand()%1000 + 1);

        int start = rand()%1000;
        int end   = rand()%1000;

        tests.push_back({arr,start,end});
    }

    // ===== Execute =====

    cout << "TOTAL TEST CASES = "
         << tests.size()
         << "\n\n";

    int tc = 1;

    for(auto &test : tests)
    {
        auto [arr,start,end] = test;

        int ans = obj.minSteps(arr,start,end);

        cout << "----------------------------------\n";
        cout << "TC #" << tc++ << "\n";

        cout << "arr = [";
        for(size_t i=0;i<arr.size();i++)
        {
            cout << arr[i];
            if(i+1<arr.size()) cout << ",";
        }
        cout << "]\n";

        cout << "start = " << start << "\n";
        cout << "end   = " << end << "\n";

        cout << "Output = " << ans << "\n";
    }

    return 0;
}