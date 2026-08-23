class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        /* Not Optimal
        int i=0;
        while(i<nums.size())
        {
            if(nums[i]==val)
            {
                nums.erase(nums.begin()+i);
            }
            else
            {
                i++;
            }
        }
        return nums.size();
        */

        int l=0, r=0;
        while(l<nums.size())
        {
            if(nums[l]!=val)
            {
                nums[r]=nums[l];
                r++;
            }
            l++;
        }
        return r;

    }
};