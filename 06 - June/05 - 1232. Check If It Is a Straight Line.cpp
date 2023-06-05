class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int n = int(coordinates.size()); // size of coordinates

        // if there are only 2 points, return true
        if (n == 2) return true;

        // if there are more than 2 points, check if they are on the same line 

        // check if the slope of the first 2 points are the same with the rest of the points 
        int x1 = coordinates[0][0], y1 = coordinates[0][1];
        int x2 = coordinates[1][0], y2 = coordinates[1][1];
        
        // if the slope of the first 2 points are the same with the rest of the points, return true
        for (int i = 2; i < n; ++i){
            int x3 = coordinates[i][0], y3 = coordinates[i][1];
            if ((y2 - y1) * (x3 - x2) != (y3 - y2) * (x2 - x1)) return false;
        }
        
        // if the slope of the first 2 points are not the same with the rest of the points, return false
        return true;
    }
};