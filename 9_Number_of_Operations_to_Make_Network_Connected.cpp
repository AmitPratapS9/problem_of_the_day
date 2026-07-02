//1319. Number of Operations to Make Network Connected : https://leetcode.com/problems/number-of-operations-to-make-network-connected/description/
/*

Disjoint Set Problem
1319. Number of Operations to Make Network Connected
Solved
Medium
Topics
premium lock icon
Companies
Hint
There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.

You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.

Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

 

Example 1:


Input: n = 4, connections = [[0,1],[0,2],[1,2]]
Output: 1
Explanation: Remove cable between computer 1 and 2 and place between computers 1 and 3.
Example 2:


Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2],[1,3]]
Output: 2
Example 3:

Input: n = 6, connections = [[0,1],[0,2],[0,3],[1,2]]
Output: -1
Explanation: There are not enough cables.
 

Constraints:

1 <= n <= 105
1 <= connections.length <= min(n * (n - 1) / 2, 105)
connections[i].length == 2
0 <= ai, bi < n
ai != bi
There are no repeated connections.
No two computers are connected by more than one cable.
*/
#include<bits/stdc++.h>
using namespace std;
class DisjointSet{
    public:
    vector<int> parent,size;

    DisjointSet(int n)
    {
        parent.resize(n,0);
        size.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
    }
    
    int findPar(int i)
    {
        if(parent[i]==i)
            return i;
    
        return parent[i]=findPar(parent[i]);
    }

    void unionBySize(int u,int v)
    {
        int ulp_u=findPar(u);
        int ulp_v=findPar(v);

        if(ulp_u==ulp_v)
            return;

        if(size[ulp_u]<size[ulp_v])
        {
            parent[ulp_u]=ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else
        {
            parent[ulp_v]=ulp_u;
            size[ulp_u]+=size[ulp_v];
        }

    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int extras=0;

        DisjointSet ds(n);
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];

            if(ds.findPar(u)==ds.findPar(v))
            {
                extras++;
            }
            else
            {
                ds.unionBySize(u,v);
            }
        }

        int cComps=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i)
                cComps++;
        }

        int reqAns=cComps-1; //we need n-1 extras, where n is different comps

        if(extras>=reqAns)
            return reqAns;
        
        return -1;
    }
};

#include <bits/stdc++.h>
using namespace std;

// Paste your DisjointSet and Solution classes here

int main()
{
    Solution obj;

    // Test Case 1
    {
        int n = 4;
        vector<vector<int>> connections = {
            {0,1},
            {0,2},
            {1,2}
        };

        cout << "Test Case 1: " << obj.makeConnected(n, connections)
             << " (Expected: 1)" << endl;
    }

    // Test Case 2
    {
        int n = 6;
        vector<vector<int>> connections = {
            {0,1},
            {0,2},
            {0,3},
            {1,2},
            {1,3}
        };

        cout << "Test Case 2: " << obj.makeConnected(n, connections)
             << " (Expected: 2)" << endl;
    }

    // Test Case 3
    {
        int n = 6;
        vector<vector<int>> connections = {
            {0,1},
            {0,2},
            {0,3},
            {1,2}
        };

        cout << "Test Case 3: " << obj.makeConnected(n, connections)
             << " (Expected: -1)" << endl;
    }

    // Test Case 4
    {
        int n = 5;
        vector<vector<int>> connections = {
            {0,1},
            {2,3},
            {3,4},
            {1,2}
        };

        cout << "Test Case 4: " << obj.makeConnected(n, connections)
             << " (Expected: 0)" << endl;
    }

    // Test Case 5
    {
        int n = 5;
        vector<vector<int>> connections = {
            {0,1},
            {2,3}
        };

        cout << "Test Case 5: " << obj.makeConnected(n, connections)
             << " (Expected: -1)" << endl;
    }

    return 0;
}