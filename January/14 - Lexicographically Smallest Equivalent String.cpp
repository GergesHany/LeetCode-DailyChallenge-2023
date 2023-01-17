#define sz(a) int((a).size())
#define all(a) (a).begin(), (a).end()
class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        vector < char > build(26); 
        iota(all(build), 'a'); // store the letters in the vector build
        for(int i = 0; i < sz(s1); i++){
           // find the max and min of the two letters
           char maxi = max(build[s1[i] - 'a'], build[s2[i] - 'a']);
           char mini = min(build[s1[i] - 'a'], build[s2[i] - 'a']);
           
           // if the max and min are the same, then continue because they are already equivalent
           if (maxi == mini) continue;

           // if the max and min are different, then change all the max to min
           for(int i = 0; i < 26; i++)
               if(build[i] == maxi)  
                   build[i] = mini;
        }
        // change the baseStr to the smallest equivalent string
        for(auto& i : baseStr) i = build[i - 'a']; 
        return baseStr;
    }
};