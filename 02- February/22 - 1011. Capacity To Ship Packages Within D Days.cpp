class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size(); // number of weights
        int l = *max_element(weights.begin(), weights.end()); // min capacity
        long long r = accumulate(weights.begin(), weights.end(), 0LL); // max capacity
        // binary search on the answer
        while(l < r){
            int sum = 0, cnt = 1; // cnt is the number of days needed
            long long mid = l + (r - l) / 2; // mid is the capacity of the ship
            // check if we can ship all the weights in mid days
            for(int i = 0; i < n; i++){
                // if the current weight is greater than the capacity of the ship then we can't ship it
                if(sum + weights[i] > mid){
                    cnt++, sum = 0; // we need another day to ship the current weight
                }
                sum += weights[i]; // add the current weight to the sum
            }
            // if the number of days needed is greater than the given days then we need to increase the capacity of the ship
            if(cnt > days) l = mid + 1;
            else r = mid; // else we can decrease the capacity of the ship
        }
        return l; // return the minimum capacity of the ship
    }
};