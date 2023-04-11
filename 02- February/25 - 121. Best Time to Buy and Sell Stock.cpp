class Solution {
public:
    int maxProfit(vector<int>& prices) {
      int ans = 0, minn = 1e9; // 1e9 is the maximum value of prices[i]
      for(int i = 0; i < prices.size(); i++){
        // minn is the minimum value of prices[i] before prices[i]
        if(prices[i] < minn){
          minn = prices[i];
        }
        // ans is the maximum value of prices[i] - minn
        if(prices[i] - minn > ans){
          ans = prices[i] - minn;
        }
      }
      return ans; // return the maximum value of prices[i] - minn
    }
};