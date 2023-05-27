class Solution {
public:
    int n; // size of stoneValue
    vector < int > dp, stoneValue; // dp[i] = max score that can be achieved by starting at i and playing optimally 

    // dp[cur] = max (sum of stones from cur to cur + 2 - dp[cur + 3], sum of stones from cur to cur + 1 - dp[cur + 2], sum of stones from cur to cur - dp[cur + 1])    
    int STONE(int cur){
        // base case
        if (cur == n) return 0;
        
        // memoization         
        if (dp[cur] > -1e9) return dp[cur];
 
        // recursion
        int sum = 0;
        for(int i = cur; i < (cur + 3) && i < n; i++){
            // sum of stones from cur to cur + 2 - dp[cur + 3] 
            sum += stoneValue[i];
            dp[cur] = max(dp[cur], sum - STONE(i + 1)) ;
        }

        // return the answer of the subproblem 
        return dp[cur];
    }


    string stoneGameIII(vector<int>& stoneValue) {
        this -> stoneValue = stoneValue; // set the stoneValue
        this -> n = int(stoneValue.size()); // set the size of stoneValue
        dp = vector < int > (n, -1e9); // set the dp array
        int score = STONE(0); // get the score of Alice - Bob
        // return the winner
        return (!score ? "Tie" : (score > 0 ? "Alice" : "Bob"));
    }
};