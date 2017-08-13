class Solution {
public:
    int gcd(int x, int y) {
        if (x == 0) {
            return y;
        } else {
            return gcd(y % x, x);
        }
    }
    
    int findGMin(vector<pair<int,int>>& vct) {
        int n = vct.size();
        assert(n > 0);
        int val = vct[0].second;
        for (int i = 0; i < n; i++) {
            val = gcd(val, vct[i].second);
        }
        return val;
    }
    
    long long findGMax(vector<pair<int,int>>& vct, int gmin) {
        long long val = gmin;
        for (auto p : vct) {
            assert(p.second % gmin == 0);
            val *= p.second / gmin;
        }
        return val;
    }
    
    string fractionAddition(string expression) {
        vector<pair<int,int>> vct;
        bool plus = true;
        bool slash = false;
        string str;
        pair<int,int> pv;
        for (auto c : expression) {
            if (c >= '0' and c <= '9') {
                str.push_back(c);
            } else if (c == '/') {
                if (plus == true) {
                    pv.first = +strtol(str.c_str(), 0, 10);
                } else {
                    pv.first = -strtol(str.c_str(), 0, 10);
                }
                slash = true;
                str = "";
            } else { // c == '+' or c == '-'
                if (slash == true) {
                    pv.second = strtol(str.c_str(), 0, 10);
                    vct.emplace_back(pv);
                    slash = false;
                    str = "";
                }
                plus = (c == '+');
            }
        }
        
        // last number
        if (slash == true) {
            pv.second = strtol(str.c_str(), 0, 10);
            vct.emplace_back(pv);
        }
        
        // get gmin, gmax
        int gmin = findGMin(vct);
        long long gmax = findGMax(vct, gmin);
        
        // count fractional numbers
        long long sum = 0;
        for (auto v : vct) {
            assert(gmax % v.second == 0);
            sum += gmax / v.second * v.first;
        }

        int val = gcd(abs(sum), gmax);
        sum /= val;
        gmax /= val;
        return to_string(sum) + "/" + to_string(gmax);
    }
};
