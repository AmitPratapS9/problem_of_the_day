//11_Accounts_Merge_L721_DisjointSet_Problem
/*

721. Accounts Merge

Medium


Given a list of accounts where each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.

Now, we would like to merge these accounts. Two accounts definitely belong to the same person if there is some common email to both accounts. Note that even if two accounts have the same name, they may belong to different people as people could have the same name. A person can have any number of accounts initially, but all of their accounts definitely have the same name.

After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order. The accounts themselves can be returned in any order.

 

Example 1:

Input: accounts = [["John","johnsmith@mail.com","john_newyork@mail.com"],["John","johnsmith@mail.com","john00@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Output: [["John","john00@mail.com","john_newyork@mail.com","johnsmith@mail.com"],["Mary","mary@mail.com"],["John","johnnybravo@mail.com"]]
Explanation:
The first and second John's are the same person as they have the common email "johnsmith@mail.com".
The third John and Mary are different people as none of their email addresses are used by other accounts.
We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
Example 2:

Input: accounts = [["Gabe","Gabe0@m.co","Gabe3@m.co","Gabe1@m.co"],["Kevin","Kevin3@m.co","Kevin5@m.co","Kevin0@m.co"],["Ethan","Ethan5@m.co","Ethan4@m.co","Ethan0@m.co"],["Hanzo","Hanzo3@m.co","Hanzo1@m.co","Hanzo0@m.co"],["Fern","Fern5@m.co","Fern1@m.co","Fern0@m.co"]]
Output: [["Ethan","Ethan0@m.co","Ethan4@m.co","Ethan5@m.co"],["Gabe","Gabe0@m.co","Gabe1@m.co","Gabe3@m.co"],["Hanzo","Hanzo0@m.co","Hanzo1@m.co","Hanzo3@m.co"],["Kevin","Kevin0@m.co","Kevin3@m.co","Kevin5@m.co"],["Fern","Fern0@m.co","Fern1@m.co","Fern5@m.co"]]
 

Constraints:

1 <= accounts.length <= 1000
2 <= accounts[i].length <= 10
1 <= accounts[i][j].length <= 30
accounts[i][0] consists of English letters.
accounts[i][j] (for j > 0) is a valid email.
*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    public:
    vector<int> parent,size;
    DisjointSet(int n)
    {
        parent.resize(n);
        size.resize(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n=accounts.size();
        DisjointSet ds(n);
        unordered_map<string,int> mapMailNode;
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<accounts[i].size();j++)
            {
                string mail=accounts[i][j];
                if(mapMailNode.find(mail)==mapMailNode.end())
                {
                    mapMailNode[mail]=i;
                }
                else
                {
                    ds.unionBySize(i,mapMailNode[mail]);
                }
            }
        }

        vector<string> mergedMail[n];
        for(auto it:mapMailNode)
        {
            string mail=it.first;
            int node=ds.findPar(it.second);
            mergedMail[node].push_back(mail);
        }

        vector<vector<string>> ans;
        for(int i=0;i<n;i++)
        {
            if(mergedMail[i].size()==0)
                continue;
            
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]); //account name
            for(auto it:mergedMail[i])
            {
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};

int main()
{
    vector<vector<string>> accounts = {
        {"John", "johnsmith@mail.com", "john_newyork@mail.com"},
        {"John", "johnsmith@mail.com", "john00@mail.com"},
        {"Mary", "mary@mail.com"},
        {"John", "johnnybravo@mail.com"}
    };

    Solution obj;
    vector<vector<string>> ans = obj.accountsMerge(accounts);

    for (auto &account : ans)
    {
        for (auto &str : account)
        {
            cout << str << " ";
        }
        cout << endl;
    }

    return 0;
}

