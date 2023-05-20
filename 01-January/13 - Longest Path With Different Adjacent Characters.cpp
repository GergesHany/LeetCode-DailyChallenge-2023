class Solution {
public:
    int dfs(vector<vector<int>>& x,int& mx,int i,string& s){
        if(x[i].size() == 0) return 1; // leaf
        vector < int > e; // edges
        int mx1 = 0, mx2 = 0; 
        for(int j = 0; j < x[i].size(); j++){
            int a = dfs(x, mx, x[i][j], s); // a = longest path from x[i][j]
            if(s[x[i][j]] == s[i]) a = 0; // if same color, reset
            if(a > mx1) 
                mx2 = mx1, mx1 = a; // mx1 = longest path, mx2 = second longest path
            else if(a > mx2) mx2 = a; // mx2 = second longest path
        }
        mx = max(mx, mx1 + mx2 + 1); // update answer
        return mx1 + 1;
    }

    int longestPath(vector<int>& par, string s) {
        int n = par.size(), mx = 1;
        vector < vector < int > > x(n, vector<int>());
        for(int i = 0; i < n; i++)
            if(~par[i]) x[par[i]].push_back(i); // build tree
        dfs(x, mx, 0, s); // call dfs
        return mx;
    }
};