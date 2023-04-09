class Solution {
public:
    // number of even numbers between a and b
    int get_even(int a, int b){
      return (b / 2) - ((a - 1) / 2);
    }

    // number of odd numbers between a and b
    int get_odd(int a, int b){
      return ((b - a) + 1) - get_even(a, b) - (a == 0);
    }

    int countOdds(int low, int high) {
       return get_odd(low, high);
    }
};