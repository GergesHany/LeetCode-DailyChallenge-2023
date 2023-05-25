class Solution {
public:
    double new21Game(int n, int k, int maxPts) {

        double curr = 1.0, ans = 0; // curr is the sum of the last maxPts elements of dp array (the ones that are not yet in the dp array) 

        // if k == 0, then we can get any number of points from 0 to n, so the probability is 1.0 (100%)
        if (!k || n >= k + maxPts) return cur;
        
        // dp[i] is the probability of getting i points
        vector < double > dp(n + 1, 0.0);
        dp[0] = 1.0; // we start with 0 points

        // we calculate the probability of getting i points by summing the probabilities of getting i - 1, i - 2, ..., i - maxPts points  
        for (int i = 1; i < n + 1; i++){
            // the probability of getting i points is the sum of the probabilities of getting i - 1, i - 2, ..., i - maxPts points divided by maxPts
            dp[i] = curr / maxPts; 

            // if i < k, then we can get any number of points from 0 to i, so we add dp[i] to curr
            if (i < k) curr += dp[i];
            
            // if i >= k, then we can get any number of points from k to i, so we add dp[i] to ans
            else ans += dp[i];

            // if i - maxPts >= 0, then we subtract dp[i - maxPts] from curr
            if (i - maxPts < 0) continue;
            curr -= dp[i - maxPts];
        } 
        
        // we return the answer 
        return ans;
    }
};