// 1833 Maximum Ice Cream bars
/*
It is a sweltering summer day, and a boy wants to buy some ice cream bars.

At the store, there are n ice cream bars. You are given an array costs of length n, where costs[i] is the price of the ith ice cream bar in coins. The boy initially has coins coins to spend, and he wants to buy as many ice cream bars as possible. 

Note: The boy can buy the ice cream bars in any order.

Return the maximum number of ice cream bars the boy can buy with coins coins.

You must solve the problem by counting sort.

 

Example 1:

Input: costs = [1,3,2,4,1], coins = 7
Output: 4
Explanation: The boy can buy ice cream bars at indices 0,1,2,4 for a total price of 1 + 3 + 2 + 1 = 7.
Example 2:

Input: costs = [10,6,8,7,7,8], coins = 5
Output: 0
Explanation: The boy cannot afford any of the ice cream bars.
Example 3:

Input: costs = [1,6,3,1,2,5], coins = 20
Output: 6
Explanation: The boy can buy all the ice cream bars for a total price of 1 + 6 + 3 + 1 + 2 + 5 = 18.
 

Constraints:

costs.length == n
1 <= n <= 105
1 <= costs[i] <= 105
1 <= coins <= 108
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        /* TC:O(n log n)
        //brute force approach
        int iceCreamBars=0;
        sort(costs.begin(),costs.end());
        for(int i=0;i<costs.size();i++)
        {
            if(coins-costs[i]>=0 && coins>0)
            {
                coins-=costs[i];
                iceCreamBars++;
            }
        
        }
        return iceCreamBars;
        */
        
        //frequency counting method
        vector<int> freq(100001,0);
        int numOfIceCreams=0;
        for(auto it:costs)
        {
            freq[it]++;
        }

        for(int i=1;i<100001;i++)
        {
            while(freq[i]>0 && coins-i>=0)
            {
                numOfIceCreams++;
                freq[i]--;
                coins-=i;
            }
        }
        return numOfIceCreams;
    }
};


int main()
{
    Solution obj;

    vector<pair<vector<int>,int>> tests = {

        {{1},1},
        {{1},0},
        {{2},1},
        {{1,1},2},
        {{1,1},1},
        {{1,2,3},6},
        {{1,2,3},5},
        {{1,2,3},1},
        {{10,6,8,7,7,8},5},
        {{1,3,2,4,1},7},

        {{1,1,1,1,1},5},
        {{1,1,1,1,1},3},
        {{5,5,5,5},20},
        {{5,5,5,5},19},
        {{100000},100000},
        {{100000},99999},
        {{100000,100000},200000},
        {{100000,100000},100000},
        {{2,2,2,2,2},10},
        {{2,2,2,2,2},9},

        {{1,2,3,4,5},15},
        {{1,2,3,4,5},14},
        {{1,2,3,4,5},3},
        {{5,4,3,2,1},15},
        {{5,4,3,2,1},5},
        {{7,8,9},6},
        {{7,8,9},7},
        {{7,8,9},15},
        {{3,3,3,3,3},12},
        {{3,3,3,3,3},13},

        {{1,100000},100001},
        {{1,100000},100000},
        {{1,99999},100000},
        {{4,2,1},4},
        {{4,2,1},3},
        {{4,2,1},2},
        {{4,2,1},1},
        {{9,8,7,6,5},10},
        {{9,8,7,6,5},30},
        {{9,8,7,6,5},35},

        {{1,1,2,2,3,3},12},
        {{1,1,2,2,3,3},6},
        {{10,20,30,40},100},
        {{10,20,30,40},99},
        {{10,20,30,40},50},
        {{50,40,30,20,10},50},
        {{50,40,30,20,10},49},
        {{1,2,2,2,5},8},
        {{1,2,2,2,5},7},
        {{1,2,2,2,5},6},

        {{100,200,300},600},
        {{100,200,300},599},
        {{100,200,300},100},
        {{1,1,1,100000},100002},
        {{1,1,1,100000},3},
        {{99999,100000},199999},
        {{99999,100000},99999},
        {{50000,50000,50000},100000},
        {{50000,50000,50000},150000},
        {{1,2,4,8,16,32},63},

        {{1,2,4,8,16,32},31},
        {{1,2,4,8,16,32},1},
        {{6,6,6,6,6,6},36},
        {{6,6,6,6,6,6},35},
        {{2,4,6,8,10},12},
        {{2,4,6,8,10},30},
        {{3,5,7,9,11},15},
        {{3,5,7,9,11},35},
        {{1,10,100,1000},1111},
        {{1,10,100,1000},110},

        {{8,1,2,2,3},7},
        {{8,1,2,2,3},8},
        {{8,1,2,2,3},16},
        {{4,4,4,4,4},8},
        {{4,4,4,4,4},20},
        {{1,2,3,4,5,6,7,8,9},45},
        {{1,2,3,4,5,6,7,8,9},44},
        {{9,9,9,9,9},18},
        {{9,9,9,9,9},17},
        {{1,100,1000,10000},11101},

        {{1,100,1000,10000},10000},
        {{999,999,999},2997},
        {{999,999,999},2996},
        {{2,3,5,7,11,13},41},
        {{2,3,5,7,11,13},10},
        {{1000,2000,3000},6000},
        {{1000,2000,3000},5999},
        {{1,1,1,1,100000},4},
        {{1,1,1,1,100000},100004},
        {{100000,99999,99998},299997},

        {{100000,99999,99998},199999},
        {{1,5,10,20,50},86},
        {{1,5,10,20,50},85},
        {{7,14,21,28},70},
        {{7,14,21,28},69},
        {{3,6,9,12,15},45},
        {{3,6,9,12,15},44},
        {{42},42},
        {{42},41}
    };

    int tc = 1;

    for(auto &test : tests)
    {
        auto costs = test.first;
        int coins = test.second;

        cout << "TC #" << tc++ << "\n";
        cout << "Costs: [";

        for(int i = 0; i < costs.size(); i++)
        {
            cout << costs[i];
            if(i + 1 < costs.size()) cout << ",";
        }

        cout << "]\n";
        cout << "Coins: " << coins << "\n";
        cout << "Output: "
             << obj.maxIceCream(costs, coins)
             << "\n\n";
    }
    return 0;
}