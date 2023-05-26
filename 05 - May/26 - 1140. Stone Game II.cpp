class Solution {
public:
    int dp[101][201]; // dp array
    vector < int > piles; // piles array

    // helper function
    int helper(int i, int m){
        // base case
        if(i >= int(piles.size())) return 0;

        // memoization
        int &ret = dp[i][m];
        if(~ret) return ret;

        // recursive case
        ret = -1e9;
        int total = 0;

        for(int j = 0; j < 2 * m; j++){
            if(i + j < int(piles.size())) total += piles[i + j]; // total stones in the current pile 
            ret = max(ret, total - helper(i + j + 1,max(m, j + 1))); // max of the current ans and the next ans
        }
       
       // return the ans
       return ret;
    }
    
    int stoneGameII(vector<int>& piles) {
        
        int sum = 0; // total stones

        this -> piles = piles; // assign the piles array
        for(auto x: piles) sum += x; // calculate the total stones
        
        memset(dp, -1, sizeof(dp)); // initialize the dp array with -1
        
        int diff = helper(0, 1); // call the helper function
       
        sum = (sum + diff) / 2; // calculate the total stones of alex
        return sum; // return the ans
    }
};