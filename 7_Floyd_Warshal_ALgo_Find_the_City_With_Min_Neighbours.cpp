// Leetcode 1334 : Find the City With the Smallest Number of Neighbors at a Threshold Distance
//This problem is based on FLoyd Warshall Algorithm

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path and whose distance is at most distanceThreshold, If there are multiple such cities, return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.

 

Example 1:



Input: n = 4, edges = [[0,1,3],[1,2,1],[1,3,4],[2,3,1]], distanceThreshold = 4
Output: 3
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 4 for each city are:
City 0 -> [City 1, City 2] 
City 1 -> [City 0, City 2, City 3] 
City 2 -> [City 0, City 1, City 3] 
City 3 -> [City 1, City 2] 
Cities 0 and 3 have 2 neighboring cities at a distanceThreshold = 4, but we have to return city 3 since it has the greatest number.
Example 2:



Input: n = 5, edges = [[0,1,2],[0,4,8],[1,2,3],[1,4,2],[2,3,1],[3,4,1]], distanceThreshold = 2
Output: 0
Explanation: The figure above describes the graph. 
The neighboring cities at a distanceThreshold = 2 for each city are:
City 0 -> [City 1] 
City 1 -> [City 0, City 4] 
City 2 -> [City 3, City 4] 
City 3 -> [City 2, City 4]
City 4 -> [City 1, City 2, City 3] 
The city 0 has 1 neighboring city at a distanceThreshold = 2.
 

Constraints:

2 <= n <= 100
1 <= edges.length <= n * (n - 1) / 2
edges[i].length == 3
0 <= fromi < toi < n
1 <= weighti, distanceThreshold <= 10^4
All pairs (fromi, toi) are distinct.
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {

        //for floyd walsh algorthm, matrix is always a node*node matrix
        vector<vector<int>> dist(n,vector<int>(n,1e9));

        for(int i=0;i<n;i++)
            dist[i][i]=0;

        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            
            dist[u][v]=wt;
            dist[v][u]=wt;
            
        }

        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(dist[i][k]!=1e9 && dist[j][k]!=1e9)
                    {
                        dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                    }
                }
            }
        }
        int minReachable=1e9;
        int ans=-1;

        for(int i=0;i<n;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && dist[i][j]<=distanceThreshold)
                {
                    cnt++;
                }
            }
            if(cnt<=minReachable)
            {
                minReachable=cnt;
                ans=i;
            }
        }
        return ans;
    }
};

int main()
{
    Solution obj;

    vector<tuple<int, vector<vector<int>>, int>> tests = {

        // Sample 1
        {
            4,
            {{0,1,3},{1,2,1},{1,3,4},{2,3,1}},
            4
        },

        // Sample 2
        {
            5,
            {{0,1,2},{0,4,8},{1,2,3},{1,4,2},{2,3,1},{3,4,1}},
            2
        },

        // Single node
        {
            1,
            {},
            5
        },

        // Two connected
        {
            2,
            {{0,1,5}},
            5
        },

        // Two disconnected
        {
            2,
            {},
            5
        },

        // Triangle
        {
            3,
            {{0,1,2},{1,2,2},{0,2,10}},
            4
        },

        // Threshold zero
        {
            3,
            {{0,1,1},{1,2,1}},
            0
        },

        // Chain
        {
            5,
            {{0,1,2},{1,2,2},{2,3,2},{3,4,2}},
            4
        },

        // Complete graph
        {
            4,
            {
                {0,1,1},
                {0,2,1},
                {0,3,1},
                {1,2,1},
                {1,3,1},
                {2,3,1}
            },
            1
        },

        // Star graph
        {
            5,
            {
                {0,1,1},
                {0,2,1},
                {0,3,1},
                {0,4,1}
            },
            2
        },

        // Disconnected components
        {
            6,
            {
                {0,1,1},
                {1,2,1},
                {3,4,1}
            },
            2
        },

        // Larger weights
        {
            4,
            {
                {0,1,100},
                {1,2,100},
                {2,3,100}
            },
            150
        },

        // Alternate path shorter
        {
            4,
            {
                {0,1,5},
                {1,2,5},
                {0,2,20},
                {2,3,1}
            },
            10
        },

        // Equal distances
        {
            4,
            {
                {0,1,2},
                {1,2,2},
                {2,3,2},
                {0,3,6}
            },
            6
        },

        // No edges
        {
            5,
            {},
            10
        },

        // Every edge weight 1
        {
            5,
            {
                {0,1,1},
                {1,2,1},
                {2,3,1},
                {3,4,1},
                {4,0,1}
            },
            2
        },

        // Threshold huge
        {
            5,
            {
                {0,1,10},
                {1,2,10},
                {2,3,10},
                {3,4,10}
            },
            1000
        },

        // One isolated node
        {
            4,
            {
                {0,1,1},
                {1,2,1}
            },
            3
        },

        // Tie-breaking test
        {
            4,
            {
                {0,1,2},
                {2,3,2}
            },
            2
        },

        // Dense graph
        {
            6,
            {
                {0,1,2},
                {0,2,3},
                {0,3,4},
                {1,2,1},
                {1,4,2},
                {2,3,2},
                {2,5,3},
                {3,4,1},
                {4,5,2}
            },
            5
        }
    };

    for (int i = 0; i < tests.size(); i++)
    {
        auto [n, edges, threshold] = tests[i];

        cout << "Test Case " << i + 1 << " : ";
        cout << obj.findTheCity(n, edges, threshold) << endl;
    }

    return 0;
}