class Solution {
public:
    int minFlipsMonoIncr(string s) {
      int n = s.size();
      vector < vector < int > > dp(n + 1, vector < int > (2, 0));
      if (s[0] == '0') dp[0][0] = 0, dp[0][1] = 1; // cost of flipping 0 to 1
      else dp[0][0] = 1, dp[0][1] = 0; // cost of flipping 1 to 0
      for (int i = 1; i < n; i++){
        if (s[i] == '0'){
          dp[i][0] = dp[i - 1][0]; // cost of flipping 0 to 0
          dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1; // cost of flipping 1 to 0
        }
        else{
          dp[i][0] = dp[i - 1][0] + 1; // cost of flipping 0 to 1
          dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]); // cost of flipping 1 to 1
        }
      }

      return min(dp[n - 1][0], dp[n - 1][1]); // return min cost of flipping 0 to 1 or 1 to 0
    }
};