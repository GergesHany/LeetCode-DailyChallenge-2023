class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int ans = 0; // the answer
        // set to store the elements of the array 
        set < int > st(arr.begin(), arr.end());
        // loop over the numbers from 1 to 2005 to find the kth missing number
        for (int i = 1; i <= 2005; i++){
          // if the number is not in the set then decrease k by 1
            if (st.find(i) == st.end()){
                k--;
                // if k is 0 then the answer is i and break the loop
                if (k == 0){
                    ans = i;
                    break;
                }
            }
        }
        return ans; // return the answer
    }
};