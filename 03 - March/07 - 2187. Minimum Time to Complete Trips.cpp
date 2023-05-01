class Solution {
#define ll long long
public:
    long long minimumTime(vector<int>& time, int totalTrips) {
        ll l = 0, r = 1, ans = time[0]; 

        // check if mid is good
        auto is_good = [&](ll mid) -> bool {
          ll sum = 0;
          for (auto & i: time) sum += mid / i;
          return sum >= totalTrips; 
        };

        while(!is_good(r)) r *= 2; // find the greatest good 

        // binary search
        while(l <= r){
            ll mid = l + (r - l) / 2;
            if (is_good(mid)) ans = mid, r = mid - 1;
            else l = mid + 1;
        }
        return ans;
    }      
};