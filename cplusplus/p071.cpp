class Solution {
public:
	vector<string> strSplit(string str) {
        stringstream ss(str);
        vector<string> ret;
		string sstr;
        while (getline(ss, sstr, '/')) {
            if (sstr.length() != 0) {
                ret.emplace_back(sstr);
            }
        }
        return ret;
    }
    
    string simplifyPath(string path) {
        vector<string> vct = strSplit(path);
		vector<string> nvct;
        for (auto sstr : vct) {
            if (sstr == ".") {
                // do nothing
            } else if (sstr == ".." ) {
                if (nvct.size() > 0) {
	                nvct.pop_back();
            	}
            } else {
                nvct.emplace_back(sstr);
            }
        }
        
        string ret = "/";
        for (auto sstr: nvct) {
            ret += sstr;
            ret += "/";
        }
		if (ret.length() > 1) {
            ret.pop_back();
        }
        return ret;
    }
};
