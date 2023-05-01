class Solution {
#define ll long long  
#define INF 1e18   
#define all(s) s.begin(), s.end()
#define sz(s) int(s.size())
public:
    int minJumps(vector<int>& arr) {
        int n = sz(arr);
        if(n == 1) return 0;
        unordered_map<int, vector<int>> mp;
        for(int i = 0; i < n; i++) mp[arr[i]].push_back(i);
        vector<int> vis(n, 0);
        queue<int> q;
        q.push(0);
        vis[0] = 1;
        int ans = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                int u = q.front();
                q.pop();
                if(u == n - 1) return ans;
                if(u - 1 >= 0 && !vis[u - 1]){
                    q.push(u - 1);
                    vis[u - 1] = 1;
                }
                if(u + 1 < n && !vis[u + 1]){
                    q.push(u + 1);
                    vis[u + 1] = 1;
                }
                for(auto v : mp[arr[u]]){
                    if(!vis[v]){
                        q.push(v);
                        vis[v] = 1;
                    }
                }
                mp[arr[u]].clear();
            }
            ans++;
        }
        return ans;
    }
};