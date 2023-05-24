class Solution {
public:
    pair<int,int> parse(string& s) {
        int a, b;
        sscanf(s.c_str(), "%d+%di", &a, &b);
        return make_pair(a, b);
    }
    
    string complexNumberMultiply(string a, string b) {
        pair<int,int> pa = parse(a);
        pair<int,int> pb = parse(b);
        
        pair<int,int> pc = make_pair(pa.first * pb.first - pa.second * pb.second,
                                     pa.first * pb.second + pb.first * pa.second);
        return to_string(pc.first) + "+" + to_string(pc.second) + "i";
    }
};
