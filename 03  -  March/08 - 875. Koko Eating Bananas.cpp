class Solution {
#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))    
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1;
        auto is_good = [&](int mid) -> bool {
           long long sum = 0;
           for (auto & i: piles)
             sum += ceill(i, mid);
           return sum <= h;     
        };
        
        int ans = 0;
        while(!is_good(r)) r *= 2;
        while(l <= r){
            long long mid = l + (r - l) / 2;
            if (is_good(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }
};