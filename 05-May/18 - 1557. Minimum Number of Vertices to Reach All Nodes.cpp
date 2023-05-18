class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        
        vector < int > indegree(n, 0); // indegree of each node
        
        // calculate the indegree of each node
        for (auto &x : edges)
            indegree[x[1]]++;
        
        // find the nodes with indegree 0 and return them as the answer
        // because they are the nodes that can't be reached from any other node 
        vector < int > ans;
        for (int i = 0; i < n; i++)
        // if the indegree of node i is 0, then it can't be reached from any other node
          if (!indegree[i]) 
            ans.push_back(i);

        // return the answer
        return ans;
    }
};
