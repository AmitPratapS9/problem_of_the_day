class Solution {
public:
    int reverseBits(int n) {
       int ans=0b00000000000000000000000000000000;
       for(int i=0;i<32;i++)
       {
        //extract the right most bit
        int rbit=n&1;
        
        //create a rbit position in ans
        ans=ans<<1;

        //adding the rbit to ans
        ans=ans|rbit;

        //rightshift n
        n=n>>1;


       } 
       return ans;
        
    }
};