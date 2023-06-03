class Solution {
public:

    int curr = 0, ans = 0; // curr is the current time taken to inform all the subordinates of a manager
    
    // dfs to find the maximum time taken to inform all the subordinates of a manager
    void dfs(vector < int > adj[], vector < int >& informTime, int src){
        // if the manager has no subordinates, then update the ans 
        if(adj[src].size() == 0){
            ans = max(ans, curr);
            return ;
        }
        // else, update the current time taken to inform all the subordinates of the manager
        curr += informTime[src];
        // call dfs for all the subordinates of the manager
        for(auto it : adj[src])
            dfs(adj, informTime, it);
        // backtrack    
        curr -= informTime[src];
    }

    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector < int > adj[n]; // adjacency list to store the subordinates of a manager

        // create the adjacency list
        for(int i = 0; i < n; i++)
            if(~manager[i])
                adj[manager[i]].push_back(i);
        // call dfs for the headID
        dfs(adj, informTime, headID);

        // return the ans
        return ans;
    }
};