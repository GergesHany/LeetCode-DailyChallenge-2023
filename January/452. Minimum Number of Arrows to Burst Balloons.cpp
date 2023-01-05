class Solution {
#define sz(s) int(s.size())
#define all(s)  s.begin(),  s.end()
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if(sz(points) == 0) return 0;
        int ans = 1;
        sort(all(points));
        int end = points[0][1]; 
        for(int i = 1; i < sz(points); i++){
            if(points[i][0] > end){ 
                ans++;
                end = points[i][1]; 
            }
            else{
                end = min(end, points[i][1]); 
            }
        }
        return ans;
    }
};