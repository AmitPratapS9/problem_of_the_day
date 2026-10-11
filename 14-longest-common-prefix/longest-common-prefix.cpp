class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string str=strs[0];
        for(int i=0;i<strs.size();i++)
        {
            int j=0;
            while(j<str.size() && j<strs[i].size() && str[j]==strs[i][j])
            {
                j++;
            }
            if(!str.empty())
            {
                str=str.substr(0,j);
            }
            else
            {
                return "";
            }
        }
        return str;
    }
};