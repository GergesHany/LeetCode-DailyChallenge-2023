class Solution {
public:      
    int maxValue(int n, int index, int maxSum) {

        // function to calculate sum of first n natural numbers 
        auto SUM = [](long long mid) -> long long {
           return 1LL * mid * (mid + 1) / 2;
        }; 

        // function to check if mid is a good value
        auto is_good = [&](int mid){
            long long sum = 0; // sum of all elements
            long long reqLeft = mid, haveLeft = index + 1; // reqLeft = required left elements, haveLeft = have left elements

            if (index == 0) sum += mid; // if index is 0, then we have to add mid to sum
            else{
                // if we have more elements than required, then we can add sum of first reqLeft elements to sum and add remaining elements to sum 
                if (haveLeft >= reqLeft)
                  sum += SUM(mid), sum += haveLeft - reqLeft;
                // if we have less elements than required, then we can add sum of first reqLeft elements to sum and add remaining elements to sum 
                else sum += SUM(mid) - SUM(reqLeft - haveLeft);
            }

            // same as above, but for right side elements 
            if (index != n - 1){
                // if we have more elements than required, then we can add sum of first reqRight elements to sum and add remaining elements to sum
                long long reqRight = reqLeft - 1;
                long long haveRight = n - index - 1;
                // if we have more elements than required, then we can add sum of first reqRight elements to sum and add remaining elements to sum
                if (haveRight >= reqRight)
                    sum += SUM(mid - 1), sum += haveRight - reqRight;
                // if we have less elements than required, then we can add sum of first reqRight elements to sum and add remaining elements to sum    
                else sum += SUM(mid - 1) - SUM(reqRight - haveRight);
            }
            // return true if sum is less than or equal to maxSum
            return sum <= maxSum;
        };

      // binary search for the answer 
      int l = 1, r = maxSum, ans = 0;
      while (l <= r){
        int mid = (l + r) >> 1;
        if (is_good(mid)) ans = mid, l = mid + 1;
        else r = mid - 1;
      }

      // return answer
      return ans;
    }
};