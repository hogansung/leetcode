class LogSystem {
public:
    LogSystem() {
        
    }
    
    void put(int id, string timestamp) {
        mp[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        { // start
            int y, m, d, h, min, sec;
            sscanf(s.c_str(), "%d:%d:%d:%d:%d:%d", &y, &m, &d, &h, &min, &sec);
            if (gra == "Year") {
                m = 0;
            } else if (gra == "Month") {
                d = 0;
            } else if (gra == "Day") {
                h = min = sec = 0;
            } else if (gra == "Hour") {
                min = sec = 0;
            } else if (gra == "Minute") {
                sec = 0;
            }
            
            char tmp[20];
            sprintf(tmp, "%d:%02d:%02d:%02d:%02d:%02d", y, m, d, h, min, sec);
            s = tmp;
        }
        { // end
            int y, m, d, h, min, sec;
            sscanf(e.c_str(), "%d:%d:%d:%d:%d:%d", &y, &m, &d, &h, &min, &sec);
            if (gra == "Year") {
                m = 13;
            } else if (gra == "Month") {
                d = 32;
            } else if (gra == "Day") {
                h = 24;
            } else if (gra == "Hour") {
                min = 60;
            } else if (gra == "Minute") {
                sec = 60;
            }
            
            char tmp[20];
            sprintf(tmp, "%d:%02d:%02d:%02d:%02d:%02d", y, m, d, h, min, sec);
            e = tmp;
        }
        
        auto it_s = mp.lower_bound(s);
        auto it_e = mp.upper_bound(e);

        vector<int> ret;
        for (auto it = it_s; it != it_e; it++) {
            ret.push_back(it->second);
        }
        return ret;
    }
    
    map<string, int> mp;
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */
