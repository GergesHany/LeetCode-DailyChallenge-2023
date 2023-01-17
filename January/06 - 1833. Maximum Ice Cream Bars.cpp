class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int cnt = 0, sum = 0;
        sort(costs.begin(), costs.end()); // sort the array to get the minimum cost first
        for (auto& i: costs){
          if (sum + i <= coins) sum += i, cnt++; // if the sum of the cost is less than the coins we have, we can buy it
          else break; // if the sum is greater than the coins we have, we can't buy it 
        }
        return cnt;   
    }
};
