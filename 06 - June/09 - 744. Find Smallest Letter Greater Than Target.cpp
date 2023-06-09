class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        char ans = 'A'; // The answer is initialized to 'A' because it is the smallest letter
        // If the letter is greater than the target, then it is the answer 
        for (auto & i: letters) if (i > target && ans == 'A') ans = i;
        // If the answer is still 'A', then the answer is the first letter in the vector , otherwise it is the answer
        return ans == 'A' ? letters[0] : ans;
    }
};