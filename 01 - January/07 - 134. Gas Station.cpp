class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
      int Idx = 0, n = gas.size(), sum = 0, total = 0;
      for(int i = 0; i < n; i++){
        sum += gas[i] - cost[i]; // sum of gas - cost from Idx to i
        total += gas[i] - cost[i]; // sum of gas - cost from 0 to i
        if(sum < 0) // if sum < 0 then we can't reach i from Idx
          Idx = i + 1, sum = 0; // so we will start from i + 1 and reset sum to 0
      }
      // if total < 0 then we can't reach any station from 0 to n - 1 
      return total >= 0 ? Idx : -1; 
    }
};
