class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        /* this method doesn't really work out due to the overflow
        vector<int> ans;
        //constructing the number
        long long num=0;
        for(int i=0;i<digits.size();i++)
        {
            num=((num*10)+digits[i]);
        }
        //adding an additonal value
        num+=1;

        cout<<"here is the num after adding:"<<num;

        //coverting the number back to array before returning
        while(num>9)
        {
            int rem=num%10;
            ans.push_back(rem);
            num=num/10;
        }
        ans.push_back(num);

        reverse(ans.begin(),ans.end());
        return ans;
        */
        /*
        //string method also didn't work out for the smae reason
        string ans="";
        for(int i=0;i<digits.size();i++)
        {
            ans+=digits[i]+'0';
        }
        int num=stoi(ans);
        num+=1;

        ans=to_string(num);

        vector<int> ret;
        while(num>9)
        {
            int rem=num%10;
            ret.push_back(rem);
            num=num/10;
        }
        ret.push_back(num);
        reverse(ret.begin(),ret.end());
        return ret;
        */

        // the simple logic is
        for (int i=digits.size()-1;i>=0;i--)
        {
            //if the digit is <9 increment by 1 and return the array
            if(digits[i]<9)
            {
                digits[i]++;
                return digits;
            }
            //otherwise we will add carry in the revious opputune digit
            digits[i]=0;
        }
        // in case a carry is still left like in the case of 9999
        digits.insert(digits.begin(),1);
        return digits;

    }
};