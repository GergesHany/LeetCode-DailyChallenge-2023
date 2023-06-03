class Solution {
#define ll long long
public:
    
    // dfs to find the number of nodes in the connected component
    void dfs(int src, vector < int >& vis, vector < int > adj[]){
        vis[src] = true;
        for(int x: adj[src])
            if(!vis[x])
                dfs(x,vis,adj);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
    
        int n = bombs.size(); // number of nodes
        vector < int > adj[n]; // adjacency list

        for(int i = 0; i < n; i++){
            
            // check if the bomb can destroy other bombs in the same connected component 
            ll r1 = bombs[i][2], x1 = bombs[i][0], y1 = bombs[i][1];
            
            // check if the bomb can destroy other bombs in the same connected component 
            for(int j = 0; j < n; j++){
                if (i == j) continue;
                // check if the bomb can destroy other bombs in the same connected component
                ll x2 = bombs[j][0], y2 = bombs[j][1], r2 = bombs[j][2];
                ll dsq = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
                // if the bomb can destroy other bombs in the same connected component
                if(dsq <= r1 * r1)
                    adj[i].push_back(j); 
            }
        
        }

        ll ans = 0; // answer
        vector < int > vis(n); // visited array
        for(int i = 0; i < n; i++){
            int cnt = 0; // number of nodes in the connected component
            dfs(i, vis, adj); 
            // count the number of nodes in the connected component
            for(int j = 0; j < n; j++) 
              if(vis[j] == 1) cnt++;

            // update the answer
            ans = max(ans, 1LL * cnt);
            // 
            fill(vis.begin(), vis.end(), 0);
        }
        // return the answer
        return ans;
    }
};