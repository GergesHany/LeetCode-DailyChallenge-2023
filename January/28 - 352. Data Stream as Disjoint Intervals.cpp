class SummaryRanges {

#define sz(s) int(s.size())
#define all(s) s.begin(), s.end()

vector < int > v; 
unordered_map < int, bool > mp;

public:
    // add number to the data structure
    void addNum(int value) {
        if(!(mp.count(value))) { // if value not exist in the data structure
          v.insert(upper_bound(all(v), value), value); // insert value in the sorted vector
          mp[value] = true;  // mark value as exist in the data structure
        }
    }
    
     vector < vector < int > > getIntervals() {
        // the answer is the vector of the intervals
        vector < vector < int > > ans = {{v[0]}};  // the first interval is the first element in the vector

        // loop on the vector and check if the current element is the next element in the last interval
        for(int i = 1; i < sz(v); i++){
            if(ans.back().back() + 1 == v[i]) {  // if the current element is the next element in the last interval
                if(sz(ans.back()) == 2) ans.back().back() = v[i];  // if the last interval has two elements, update the last element
                else ans.back().push_back(v[i]);  // if the last interval has one element, add the current element to the last interval
            }
            // if the current element is not the next element in the last interval
            else {
                if(sz(ans.back()) == 1) // if the last interval has one element, add the first element to the last interval
                  ans.back().emplace_back(ans.back()[0]); // add the first element to the last interval 
                ans.push_back({v[i]});  // add new interval with the current element
            }
        }
        // if the last interval has one element, add the first element to the last interval
        if(sz(ans.back()) == 1)
          // add the first element to the last interval
           ans.back().emplace_back(ans.back()[0]); 

        return ans; // return the answer
    }
};