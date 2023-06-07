class Solution {
public:
    int minFlips(int a, int b, int c) {
      int ans = 0; // the number of flips

      // convert to binary representation using bitset
      bitset < 32 > A(a), B(b), C(c);
      
      for (int i = 0; i < 32; i++){
        // check if the ith bit of c is different from the ith bit of a or b
        if ((A[i] | B[i]) != C[i]){
          // if the ith bit of c is 0, we need to flip both a and b  
          if (C[i] == 0) ans += (A[i] + B[i]);
          // if the ith bit of c is 1, we need to flip either a or b
          else ans++;
        }
      }
      // return the number of flips
      return ans;
    }
};