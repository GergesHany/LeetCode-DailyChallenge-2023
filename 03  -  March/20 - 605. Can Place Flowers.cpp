class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sum = 0;
        int m = flowerbed.size();
        for(int i = 0; i < m; i++){
            if(flowerbed[i] == 0 && (i == 0 || flowerbed[i - 1] == 0) && (i == m - 1 || flowerbed[i + 1] == 0)){
                flowerbed[i] = 1;
                sum++;
            }
        }
        return sum >= n;
    }
};