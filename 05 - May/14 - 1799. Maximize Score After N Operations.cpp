class Solution {
// some definitions    
#define ll long long  
#define sz(nums) int(nums.size())
#define mod 1000000007
public:
  ll full = 0; // full mask (make all bits 1)
  ll dp[1 << 16][16]; // dp array
  vector < int > nums; // nums vector

  // get bit at position pos from mask
  bool getbit(ll mask, int pos){
    return (mask >> pos) & 1;
  }

  // get the maximum score
  ll get_max(ll mask, int Idx){
    // base case (all bits are 1)
    if (mask == full) return 0; 

    // memoization
    ll &ret = dp[mask][Idx];
    if (~ret) return ret;
    
    ret = 0;

    // try all pairs of numbers 
    for (int bit = 0; bit < sz(nums); bit++){
      // if the bit is already taken then skip it
      if (getbit(mask, bit)) continue; 
      for (int bit2 = bit + 1; bit2 < sz(nums); bit2++){
        // if the bit is already taken then skip it
        if (getbit(mask, bit2)) continue;
        // take the max between skip and take this pair of numbers
        ret = max(ret, get_max(mask | (1LL << bit) | (1LL << bit2), Idx + 1) + (Idx + 1) * __gcd(nums[bit], nums[bit2]));
        ret %= mod; // modulo
      }
    }
    // return the answer
    return ret %= mod;
  }


  int maxScore(vector<int>& nums) {
    full = (1LL << sz(nums)) - 1; // full mask
    this -> nums = nums; // copy nums to this -> nums
    memset(dp, -1, sizeof(dp)); // initialize dp with -1
    return get_max(0, 0); // return the answer
  }

};