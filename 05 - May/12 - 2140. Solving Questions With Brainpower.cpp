class Solution {
public:
    long long dp[int(1e5 + 5)]; // dp array 
    vector < vector < int > > questions; // questions vector 
    long long get_min(int Idx){
      if (Idx >= int(questions.size())) return 0; // base case
      
      // memo
      long long &ret = dp[Idx]; 
      if (~ret) return ret;
  
      // skip this question
      ret = get_min(Idx + 1);

      // take the max between skip and take this question 
      ret = max(ret, get_min(Idx + questions[Idx][1] + 1) + questions[Idx][0]);
      return ret;
    }

    long long mostPoints(vector<vector<int>>& questions) {
      this -> questions = questions;
      memset(dp, -1, sizeof(dp));
      return get_min(0);
    }
};