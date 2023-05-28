class Solution {
public:
    int dp[1005][1005]; // dp array
    vector < int > cuts; // cuts array
    // i = starting index, j = ending index 
    int solve(int i, int j){
         
        // base case 
        if (i > j) return 0;
        
        // if already calculated
        int& ret = dp[i][j];
        if (~ret) return ret;
        
        // try all possible cuts
        ret = 1e9;
        for (int Idx = i; Idx <= j; Idx++)
            ret = min(ret, cuts[j + 1] - cuts[i - 1] + solve(i, Idx - 1) + solve(Idx + 1, j)); 
        return ret;
    }

    int minCost(int n, vector<int>& cuts) {     
        int sz = cuts.size(); // number of cuts
        memset(dp, -1, sizeof(dp)); // initialize dp array with -1
        cuts.insert(cuts.begin(), 0); // insert 0 at the beginning
        cuts.push_back(n); // insert n at the end
        // sort the cuts array
        sort(cuts.begin(), cuts.end());
        this -> cuts = cuts; // assign cuts array to this -> cuts
        // call solve function with starting index = 1 and ending index = sz 
        return solve(1, sz);
    }
};