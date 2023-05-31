class UndergroundSystem {
public:
    map < int, pair < int,string > > m; // map to store id, {time, station}
    map < string, pair < int, int > > p; // map to store {start, end}, {total time, count}
    UndergroundSystem() {
        // clear both maps
        m.clear();
        p.clear();
    }
    
    void checkIn(int id, string s, int t) {
       m[id] = {t,s}; // store id, {time, station}
    }
    
    void checkOut(int id, string s, int t) {
        // get the start station and end station in the form of string  
        string d = m[id].second + " " + s;
        
        // get the total time and count of the start and end station 
        auto &i = p[d];
        
        // update the total time and count of the start and end station
        i.first += t - m[id].first, i.second++;
    }
    
    double getAverageTime(string s, string e) {
        // get the start station and end station in the form of string 
        string temp = s + " " + e;
        // return the average time of the start and end station
        return (double)p[temp].first / p[temp].second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */