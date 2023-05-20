class Solution {
public:
    int snakesAndLadders(vector<vector<int>> &board) {
        
        int lbl = 1; // label of the cell in the board
        int n = board.size();
        vector < int > columns(n); // columns of the board
        vector < pair < int, int > > cells(n * n + 1); // cells of the board
        iota(columns.begin(), columns.end(), 0); // fill the columns with 0, 1, 2, ..., n - 1
        
        // fill the cells of the board
        for (int row = n - 1; row >= 0; row--) {
            for (int column : columns) { // columns is reversed for odd rows
                cells[lbl++] = {row, column}; // label the cell with lbl and store it in cells vector
            }
            reverse(columns.begin(), columns.end()); // reverse the columns for the next row
        }

        vector < int > dist(n * n + 1, -1); // distance of each cell from the start cell
        dist[1] = 0; // distance of the start cell from itself is 0
        queue < int > q; // queue for BFS
        q.push(1); // push the start cell into the queue
 
        // BFS 
        while (!q.empty()) {
            int curr = q.front(); // current cell in the queue
            q.pop(); // pop the current cell from the queue

            // check the next 6 cells from the current cell 
            for (int next = curr + 1; next <= min(curr + 6, n * n); next++) {
                auto [row, column] = cells[next]; // get the row and column of the next cell
                // if the next cell is a snake or ladder, then go to the destination cell of the snake or ladder otherwise go to the next cell
                int destination = board[row][column] != -1 ? board[row][column] : next; 

                // if the destination cell is not visited yet, then update the distance of the destination cell and push it into the queue
                if (dist[destination] == -1) {
                    dist[destination] = dist[curr] + 1; // update the distance of the destination cell
                    q.push(destination); // push the destination cell into the queue
                }
            }
        }
        
        int ans = dist[n * n]; // distance of the last cell from the start cell 
        return ans; // return the distance of the last cell from the start cell
    }
};