class Solution {
#define all(s)  s.begin(),  s.end()
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {   
      int Idx = 0; // index of projects 
      int n = profits.size(); // number of projects
      priority_queue< pair < int, int > > pq; // max heap
      vector < pair < int, int > > projects(n); // pair of capital and profit
      // store capital and profit in vector of pairs
      for(int i = 0; i < n; i++)
        projects[i] = {capital[i], profits[i]}; 

      sort(all(projects)); // sort projects by capital 

      int ans = w; // current capital
      while(k--){
        // add all projects that can be done with current capital
        while(Idx < n && projects[Idx].first <= ans)
          pq.push({projects[Idx].second, projects[Idx].first}), Idx++;
        if(pq.empty()) break; // no more projects can be done
        ans += pq.top().first; // add profit of project with max profit
        pq.pop(); // remove project with max profit
      }
      return ans; // return current capital
    }
};