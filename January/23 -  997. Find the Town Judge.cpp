class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector < int > indegree(n + 1, 0), outdegree(n + 1, 0); // indegree = incomming edges, outdegree = outgoing edges
        for(auto x: trust){ 
          // x[1] has incoming edge and x[0] has outgoing edge
            outdegree[x[0]]++;  // count outgoing edges
            indegree[x[1]]++;  // count incoming edges
        }
        for(int i = 1; i <= n; i++)
            // if indegree == n - 1 and outdegree == 0 then this is the judge 
            if(indegree[i] == n - 1 && outdegree[i] == 0) return i;
        // if no judge found return -1     
        return -1;
    }
};
