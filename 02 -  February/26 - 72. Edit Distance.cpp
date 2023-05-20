class Solution {
#define sz(s) int(s.size())
#define ll long long
public:
    string s, t; // s = word1, t = word2
    ll dp[505][505]; // dp[i][j] = min cost to convert s[i..] to t[j..]

    // get_min_cost(i, j) = min cost to convert s[i..] to t[j..]
    ll get_min_cost(int i, int j){
        // base case
        if (i == sz(s)) // s is empty so we need to insert all chars in t
          return sz(t) - j;

        if (j == sz(t)) // t is empty so we need to delete all chars in s
          return sz(s) - i;

        // memoization
        ll &ret = dp[i][j];
        if (~ret) return ret; 
 
        // recursive case

        if (s[i] == t[j]) // no need to do anything
          ret = get_min_cost(i + 1, j + 1);
        
        else{
          // insert
          ret = 1 + get_min_cost(i, j + 1);
          // delete
          ret = min(ret, 1 + get_min_cost(i + 1, j));
          // replace
          ret = min(ret, 1 + get_min_cost(i + 1, j + 1));
        }
        
        return ret; // return the min cost
    }

    int minDistance(string word1, string word2) {
        s = word1, t = word2; // s = word1, t = word2
        memset(dp, -1, sizeof(dp)); // initialize dp with -1
        return get_min_cost(0, 0); // return the min cost to convert s to t
    }
};
