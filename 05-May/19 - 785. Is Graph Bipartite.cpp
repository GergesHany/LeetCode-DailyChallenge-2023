class Solution {
public:
   vector < int > color; // color of each node
   vector < int > adj[105]; // adjacency list of the graph
   bool is_bipartite = true; // boolean variable to check if the graph is bipartite or not

   // dfs function to check if the graph is bipartite or not
   void dfs(int node, int c){
     color[node] = c; // color the node with color c
     for (int child : adj[node]){
       // if the child is not colored
       if (color[child] == -1){
        // color the child with the opposite color of the parent 
         dfs(child, c ^ 1); 
       }
       
      // if the child is colored with the same color as the parent
       else if (color[child] == color[node]){
        // then the graph is not bipartite
         is_bipartite = false;
       }
     }
   } 

    bool isBipartite(vector<vector<int>>& graph) {
        
      int n = int(graph.size()); // number of nodes in the graph
      color = vector < int > (n + 1, -1); // initialize the color of each node with -1

      // build the adjacency list of the graph
      for (int i = 0; i < n; i++){ 
        for (int j = 0; j < int(graph[i].size()); j++){
          adj[i].push_back(graph[i][j]);
          adj[graph[i][j]].push_back(i);
        }
      }

      // call dfs for each node
      for (int i = 0; i < n; i++){
        if (color[i] == -1){
          dfs(i, 0);
        }
      }
      
      // return the answer
      return is_bipartite;
    }
};