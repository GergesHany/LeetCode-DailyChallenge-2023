class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector < int > ans; // answer
        // build[i]: the minimum value of the last element of a subsequence of length i
        vector < int > build(int(obstacles.size()) + 1, 1e9);
        for (auto & i: obstacles){
            // find the index of the smallest element that is greater than or equal to i
            auto it = upper_bound(build.begin(), build.end(), i) - build.begin();
            build[it] = i; // update the value of build[it]
            ans.push_back(it + 1); // update the answer
        }
        return ans; // return the answer
    }
};