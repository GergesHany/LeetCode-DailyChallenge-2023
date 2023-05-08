class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
       // the sum of the elements in the main diagonal and the secondary diagonal
       long long sum = 0; 

       // the size of the matrix
       int n = mat[0].size();

       // the sum of the elements in the main diagonal 
       for (int i = 0; i < n; i++) sum += mat[i][i];

        // the sum of the elements in the secondary diagonal       
       for (int i = 0; i < n; i++)
         for (int j = 0; j < n; j++)
            if ((i + j) == n - 1 && i != j)
               sum += mat[i][j];

        // return the sum
        return sum;        
    }
};