class Solution {
public:
    string BigAdd(string s, string t){
        string res;
        int sz = max(s.size(), t.size());
        reverse(s.begin(), s.end());
        reverse(t.begin(), t.end());
        char carry = '0';
        int e = 0, f = 0;
        for(int i = 0; i < sz || carry != '0'; i++){
          e = (i >= s.size() ? 0 : s[i] - '0');
          f = (i >= t.size() ? 0 : t[i] - '0');
          int tmp = (carry - '0') + e + f;
          carry = (tmp / 10) + '0';
          res.push_back(tmp % 10 + '0');
        }
        reverse(res.begin(), res.end());
        while(res[0] == '0') res.erase(res.begin());
        return res;
    }

    vector<int> addToArrayForm(vector<int>& num, int k) {
        string number;
        for (auto & i: num)
           number += to_string(i);
        
        string temp = BigAdd(number, to_string(k));
        vector < int > ans(int(temp.size()));
        
        for (int i = 0; i < int(temp.size()); i++){
            ans[i] = temp[i] - '0'; 
        }     

        return ans;
    }
};