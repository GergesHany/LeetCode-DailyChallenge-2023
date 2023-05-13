class Solution {
public:
    int z, o; // the number of zeros and ones
    long long dp[int(1e5 + 5)]; // dp array
    long long count(long long val){ // count the number of good strings
        // base case
        if (val <= 0) return val == 0; 
       
        // memo
        long long &ret = dp[val]; 
        if (~ret) return ret;
        
        // count the number of good strings 
        return ret = (count(val - o) + count(val - z)) % int(1e9 + 7);
    }

    int countGoodStrings(int low, int high, int zero, int one) {
        int ans = 0; // the answer
        o = one, z = zero; // initialize the number of zeros and ones
        memset(dp, -1, sizeof(dp)); // initialize dp with -1

        // count the number of good strings in the range [low, high]
        for (int i = low; i <= high; i++)
            ans = (ans + int(1e9 + 7) + count(i)) % int(1e9 + 7); 

        // return the answer        
        return ans;
    }
};