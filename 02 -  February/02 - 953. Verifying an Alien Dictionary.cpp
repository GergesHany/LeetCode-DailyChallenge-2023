class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int j = 0;
        map < char, int > mp;
        for(auto &it : order) mp[it] = j++; // map each char to its index in the order string

        for(int i = 1; i < words.size(); i++){

            bool flag = false; // flag to check if the first string is smaller than the second string  
            string first = words[i - 1]; // first string
            string second = words[i]; // second string

            int minLen = min(first.size(), second.size()); // get the minimum length of the two strings

            for(int j = 0; j < minLen; j++){
                // if the first string is smaller than the second string
                if(mp[first[j]] < mp[second[j]]) {
                    flag = true; // set the flag to true 
                    break; // break the loop
                }

                if(mp[first[j]] > mp[second[j]]) return false; // if the first string is greater than the second string return false
            }
            if(!flag && first.size() > second.size()) return false; // if the flag is false and the first string is greater than the second string return false
        }
        return true; // return true if all the strings are sorted
    }
};
