class Solution {
#define all(s) s.begin(), s.end()
public:
    vector < int > a; // nums1
    int dp[2005][2005]; // dp[i][j]: the answer for the subproblem of nums1[i..n] and nums2[j..m]
    vector < int > Idx[2005]; // Idx[i]: the indices of i in nums2

    int get_max(int i, int j){
      if (i == int(a.size())) return 0; // base case

      // memoization
      int &ret = dp[i][j];
      if (~ret) return ret;
      
      ret = get_max(i + 1, j); // skip nums1[i]
      auto it = upper_bound(all(Idx[a[i]]), j); // find the index of the smallest element that is greater than or equal to j

      // if there is an element in Idx[a[i]] that is greater than or equal to j then we can take nums1[i]
      if (it != Idx[a[i]].end())
        ret = max(ret, 1 + get_max(i + 1, *it));

      // return the answer  
      return ret;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      a = nums1; // copy nums1 to a

      // build Idx
      for (int i = 0; i < int(nums2.size()); i++)
        Idx[nums2[i]].push_back(i + 1);

      // initialize dp with -1    
      memset(dp, -1, sizeof(dp));

      // return the answer
      return get_max(0, 0);
    }
};