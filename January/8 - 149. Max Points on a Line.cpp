// number of points that lie on the same straight line "equal" to the number of points that have the same slope
class Solution {
public: 
    // get slope between two points
    long double get_slope(int x1, int y1, int x2, int y2){
      return (x1 == x2) ? INT_MAX : (long double)(y1 - y2) / (x1 - x2);
    }

    int maxPoints(vector<vector<int>>& points) {
       int ans = 1; // at least one point
        for(int i = 0; i < points.size(); i++){
          int x = points[i][0], y = points[i][1]; // current point
          map < long double, int > mp; // slope, count
          for (int j = 0; j < points.size(); j++){
            if (i == j) continue; // same point
            int x1 = points[j][0], y1 = points[j][1]; // other point
            long double slope = get_slope(x, y, x1, y1); // get slope
            mp[slope]++; // increment count of this slope by 1
          }
          for (auto it : mp) 
            ans = max(ans, it.second); // get max count of points with same slope 
        }
        return ans; // return max count
    }
};
