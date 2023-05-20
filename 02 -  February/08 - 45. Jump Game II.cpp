class Solution {
#define sz(s) int(s.size())
public:
    vector < int > num, dp;
    // dp[i] = min number of jumps to reach the end from i
    int get_min(int Idx){
       // base case 
       if (Idx >= sz(num) - 1) 
         return Idx == sz(num) - 1 ? 0 : 1e9; // if we are at the end return 0 else return 1e9
      
      // memoization
      int & ret = dp[Idx]; // current state
      if (~ret) return ret; // if we have already calculated the answer return it
      ret = 1e9; // initialize the answer with 1e9

      // transition 
      for (int i = 1; i <= num[Idx]; i++) 
        ret = min(ret, 1 + get_min(Idx + i));

      return ret; // return the answer  
    }

    int jump(vector<int>& nums) {
      num = nums; // copy the array
      dp.assign(sz(nums) + 10, -1); // initialize the dp array with -1
      return get_min(0); // call the function
    }
};
