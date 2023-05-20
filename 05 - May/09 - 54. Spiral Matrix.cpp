class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {

        vector < int > ans; // to store the answer
        int n = matrix.size(), m = matrix[0].size();

        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        
        // build the answer
        while(top <= bottom && left <= right){
            // go right 
            for(int i = left; i <= right; i++) ans.push_back(matrix[top][i]);

            // we have already visited the top row
            top++; 

            // go down            
            for(int i = top; i <= bottom; i++) ans.push_back(matrix[i][right]);
            
            // we have already visited the right column
            right--;

            // go left
            if(top <= bottom){
                for(int i = right; i >= left; i--) ans.push_back(matrix[bottom][i]);
                // we have already visited the bottom row
                bottom--;
            }

            // go up
            if(left <= right){
                for(int i = bottom; i >= top; i--) ans.push_back(matrix[i][left]);
                // we have already visited the left column
                left++;
            }
        }
        // return the answer
        return ans;
    }
};