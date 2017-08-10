class Solution {
public:
    void split(vector<string>& vct, string& equation) {
        stringstream ss(equation);
        string str;
        while (getline(ss, str, '=')) {
            vct.emplace_back(str);
        }
    }
    
    pair<int,int> parse(string str) {
        pair<int, int> pv;
        string s_val = "";
        for (auto c : str) {
            if (c == '+' or c == '-') {
                if (s_val.length() != 0) {
                    pv.second += strtol(s_val.c_str(), 0, 10);
                    s_val = "";
                }
                s_val.push_back(c);
            } else if (c == 'x') {
                if (s_val.back() == '+' or 
                    s_val.back() == '-' or 
                    s_val.length() == 0) {
                    s_val.push_back('1');
                }
                pv.first += strtol(s_val.c_str(), 0, 10);
                s_val = "";
            } else {
                s_val.push_back(c);
            }
        }
        
        if (s_val.length() != 0) {
            pv.second += strtol(s_val.c_str(), 0, 10);
        }
        
        return pv;
    }
    
    string solveEquation(string equation) {
        vector<string> vct;
        split(vct, equation);
        
        assert(vct.size() == 2);
        pair<int,int> lv = parse(vct[0]);
        pair<int,int> rv = parse(vct[1]);
        
        if (lv.first < rv.first) {
            lv.first = rv.first - lv.first;
            rv.second = lv.second - rv.second;
        } else {
            lv.first = lv.first - rv.first;
            rv.second = rv.second - lv.second;
        }
        
        if (lv.first == 0 and rv.second == 0) {
            return "Infinite solutions";
        } else if (lv.first == 0) {
            return "No solution";
        } else {
            rv.second /= lv.first;
            return "x=" + to_string(rv.second);
        }
    }
};
