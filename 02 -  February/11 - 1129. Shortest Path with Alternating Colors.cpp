class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adj(n); // node, color
        for (auto& redEdge : redEdges) 
            adj[redEdge[0]].push_back({redEdge[1], 0}); // 0 for red
        
        for (auto& blueEdge : blueEdges) 
            adj[blueEdge[0]].push_back(make_pair(blueEdge[1], 1)); // 1 for blue

        vector<int> answer(n, -1); // -1 for not visited
        vector<vector<bool>> visit(n, vector<bool>(2)); // 2 for red and blue
        queue<vector<int>> q; // node, steps, prevColor

        q.push({0, 0, -1}); // 0 for node, 0 for steps, -1 for prevColor
        visit[0][1] = visit[0][0] = true, answer[0] = 0; // 0 for red and blue and 0 for steps for node 0 

        while (!q.empty()) {
            auto element = q.front(); // node, steps, prevColor
            int node = element[0]; // node
            int steps = element[1], prevColor = element[2]; // steps, prevColor
            q.pop(); // remove the first element

            // if the node is visited with the same color, then continue
            for (auto& [neighbor, color] : adj[node]) {
                // if the neighbor is not visited with the same color, then push it to the queue
                if (!visit[neighbor][color] && color != prevColor) {
                    visit[neighbor][color] = true; // mark the neighbor as visited with the same color
                    q.push({neighbor, 1 + steps, color}); // push the neighbor to the queue
                    if (answer[neighbor] == -1) answer[neighbor] = 1 + steps; // if the neighbor is not visited before, then update the answer
                }
            }
        }
        return answer; // return the answer
    }
};
