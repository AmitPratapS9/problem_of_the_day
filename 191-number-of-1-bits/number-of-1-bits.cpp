class Solution {
public:
    int hammingWeight(int n) {
        /* the principle here is everytime we do
           n=n&(n-1) and count each time we'll until number becomes zero
           we do this because, n&n-1 get's rid of rightmost set bit with each operation

           e.g. take int n=15;
           starting_int         n         n-1        result (n&n-1)
           15                  1111       1110       1110 (14)
           14                  1110       1101       1100 (12)
           12                  1100       1011       1000 (8)
           8                   1000       0111       0000 (0)
           so in 4 iterations, we removed all set bits, so the set bits must beequal to number of iterations via n=n&n-1.
        */   
        int count=0;
        while(n>0)
        {
            n=n&(n-1);
            count++;
        }
        return count;
    }
};