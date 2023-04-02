class Solution {
public:
    int totalFruit(vector<int>& fruits) {
       int ans = 0;
       map < int, int > freq; // freq of each fruit
       int cnt_diff = 0; // number of different fruits
       // [L, R] is the current window of fruits
       int L = 0, R = 0, n = fruits.size();  
       // R is the right pointer of the window
       while(R < n && L < n){
          freq[fruits[R]]++; // add the new fruit
          if (freq[fruits[R]] == 1) cnt_diff++; // if it's a new fruit then increase the number of different fruits
          if (cnt_diff <= 2){ // if the number of different fruits is less than or equal to 2 then we can add the new fruit
            ans = max(ans, R - L + 1); // update the answer
          }
          else{
            while(L < R && cnt_diff > 2){ // if the number of different fruits is greater than 2 then we need to remove the leftmost fruit
              freq[fruits[L]]--; // remove the leftmost fruit
              if (!freq[fruits[L]]) cnt_diff--; // if the leftmost fruit is the last one then decrease the number of different fruits
              L++; // move the left pointer to the right
            }
          }
          R++; // move the right pointer to the right
       }      
       return ans; // return the answer 
    }
};
