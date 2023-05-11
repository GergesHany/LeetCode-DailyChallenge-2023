class Solution {
#define all(s) s.begin(), s.end()
public:
    int dp[2005][2005]; // the dp state is the index of the first array and the index of the second array
    vector < int > a, b; // the two arrays
    vector < int > Idx[2005]; // the index of each element in the second array

    // the function returns the maximum number of uncrossed lines
    int get_max(int i, int j){
      if (i == int(a.size())) return 0; // if we reached the end of the first array
      // if we reached the end of the second array, we can't draw any line
      if (j == -1){
        int ans = 0; // the answer
        ans = max(ans, get_max(i + 1, j)); // we skip the current element
        // we try to draw a line between the current element and the next element in the second array
        auto it = lower_bound(all(Idx[a[i]]), j);
        if (it != Idx[a[i]].end())
        // we draw a line between the current element and the next element in the second array
          ans = max(ans, 1 + get_max(i + 1, *it)); 
        // we return the answer  
        return ans;
      } 

     // if we already calculated the answer for this state, we return it
      int &ret = dp[i][j];
      if (~ret) return ret;

      ret = get_max(i + 1, j); // we skip the current element

      // we try to draw a line between the current element and the next element in the second array
      auto it = upper_bound(all(Idx[a[i]]), j);
      if (it != Idx[a[i]].end())
        ret = max(ret, 1 + get_max(i + 1, *it));
      // we return the answer
      return ret;
    }

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      a = nums1, b = nums2; // we store the two arrays
      memset(dp, -1, sizeof(dp)); // we initialize the dp array with -1

      // we store the index of each element in the second array
      for (int i = 0; i < int(nums2.size()); i++)
        Idx[nums2[i]].push_back(i);  

      // we return the answer
      return get_max(0, -1);
    }
};