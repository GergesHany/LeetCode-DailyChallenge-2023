class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector < vector < int > > ans;
        
        for(auto &i: intervals){
            // if the current interval is less than the new interval then push it to the answer
            if(i[1] < newInterval[0]) ans.push_back(i);
            // if the current interval is greater than the new interval then push the new interval to the answer and then push the current interval
            else if(newInterval[1] < i[0]){
                ans.push_back(newInterval);
                newInterval = i;
            }   
            else{
                // if the current interval is overlapping with the new interval then merge them and update the new interval
                newInterval[0] = min(newInterval[0], i[0]);
                newInterval[1] = max(newInterval[1], i[1]);
            }    
        }
        ans.push_back(newInterval);
        return ans;
    }
};