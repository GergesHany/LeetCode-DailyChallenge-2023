class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {

    int val = 1;
    int top = 0, bottom = n - 1, left = 0, right = n - 1;
    vector < vector < int > > matrix(n, vector < int > (n));    
    
    // build the answer
    while(top <= bottom && left <= right){
         // go right 
         for(int i = left; i <= right; i++) matrix[top][i] = val++;

          // we have already visited the top row
          top++; 

          // go down            
          for(int i = top; i <= bottom; i++) matrix[i][right] = val++;
          
          // we have already visited the right column
          right--;

          // go left
          if(top <= bottom){
              for(int i = right; i >= left; i--) matrix[bottom][i] = val++;
              // we have already visited the bottom row
              bottom--;
          }

          // go up
          if(left <= right){
              for(int i = bottom; i >= top; i--) matrix[i][left] = val++;
              // we have already visited the left column
              left++;
          }
      }

      return matrix;
    }
};