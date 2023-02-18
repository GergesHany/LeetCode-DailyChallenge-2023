class Solution {
public:
    int dp[45]; // dp array to store the result of the subproblems
    int Tribonacci(int n){ 
      // base case 
      if (n <= 2) return 0 + (n > 0);
      // if the result is already computed, return it
      int &ret = dp[n]; 
      if (~ret) return ret;
      // recursive case to compute the result of the subproblems and store it in the dp array 
      return ret = Tribonacci(n - 1) + Tribonacci(n - 2) + Tribonacci(n - 3);
    }
    
    int tribonacci(int n) {
         memset(dp, -1, sizeof(dp)); // initialize the dp array with -1
         return Tribonacci(n); // call the recursive function
    }
};