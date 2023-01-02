class Solution {
#define sz(s) int(s.size())  
public:
    bool wordPattern(string pattern, string s) {
        stringstream ss(s); // string stream to split the string
        vector < string > vec;
        while(ss >> s)
            vec.push_back(s); // split the string into vector of strings
        if (vec.size() != pattern.size()) return false; // if the size of the vector and the pattern are not equal return false

        map < char, string > mp; // map to store the pattern and the string
        map < string, char > mp2; // map to store the string and the pattern

        for(int i = 0 ; i < sz(pattern); i++){
           // if the pattern and the string are not found in the maps
            if(mp.find(pattern[i]) == mp.end() && mp2.find(vec[i]) == mp2.end()) 
                mp[pattern[i]] = vec[i], mp2[vec[i]] = pattern[i]; // insert them in the maps

            // if the pattern and the string are found in the maps
            else if(mp.find(pattern[i]) != mp.end() && mp2.find(vec[i]) != mp2.end()){
                if(mp[pattern[i]] != vec[i] || mp2[vec[i]] != pattern[i]) 
                    return false; // if the pattern and the string are not equal return false
            }
            else return false; // if the pattern and the string are not found in the maps return false
        }
        return true;
    }  
};
