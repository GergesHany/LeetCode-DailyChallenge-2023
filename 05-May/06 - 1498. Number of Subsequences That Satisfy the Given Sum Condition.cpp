
class Solution {
const int mod = 1e9 + 7; // the answer must be modulo 1e9 + 7
public:
    int numSubseq(vector<int>& nums, int target) {

      long long ans = 0; // the answer
      sort(nums.begin(), nums.end()); // sort the array to use binary search

      // fast power function
      auto fast_pow = [&](long long base, long long power){
        long long res = 1;
        while (power){
          if (power & 1) res = (res * base) % mod;
          base = (base * base) % mod;
          power >>= 1;
        }
        return res;
      };
 
      
      for (int i = 0; i < int(nums.size()); i++){
        // find the index of the largest element that is less than or equal to target - nums[i] 
        long long j = upper_bound(nums.begin(), nums.end(), target - nums[i]) - nums.begin() - 1;
        // if j >= i then the number of subsequences that satisfy the condition is 2 ^ (j - i) 
        if (j >= i) ans = (ans + fast_pow(2, j - i)) % mod;
      }   
      // return the answer
      return ans;         
    }
};