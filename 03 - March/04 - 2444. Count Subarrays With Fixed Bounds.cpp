class Solution {
#define sz(s) int(s.size())    
#define all(s) s.begin(), s.end()    
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
       long long ans = 0;
       int Idx_min = -1, Idx_max = -1, last = -1;
       for (int i = 0; i < sz(nums); i++){
          if (nums[i] == minK) Idx_min = i;
          if (nums[i] == maxK) Idx_max = i;
          if (nums[i] > maxK || nums[i] < minK) last = i, Idx_min = Idx_max = -1;
          if (~Idx_min && ~Idx_max) ans += min(Idx_min, Idx_max) - last;
       }
       return ans;
    }
};