#define ceill(n, m) (((n) / (m)) + ((n) % (m) ? 1 : 0))
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int curr = 1, ans = 0;
        sort(tasks.begin(), tasks.end()); // sort the tasks 
        for (int i = 1; i < tasks.size(); i++){
            if (tasks[i] == tasks[i - 1]) curr++; // if the current task is equal to the previous task then increment the current task
            else{ // if the current task is not equal to the previous task then we have to do the previous task
               if (curr == 1) return -1; // if the current task is 1 then we can't do it so return -1
               ans += ceill(curr, 3); // if the current task is not 1 then we can do it so we add the ceil of the current task by 3 to the answer
               // add the ceil of the current task by 3 to the answer because this is the minimum number of rounds we need to do the current task
               curr = 1; // reset the current task to 1
            }
        }
        // if the current task is 1 then we can't do it so return -1 else we can do it so we add the ceil of the current task by 3 to the answer
        return curr == 1 ? -1 : ans + ceill(curr, 3);
    }
};
