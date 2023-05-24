class Solution {
public:
    void split(vector<int>& vct, string version) {
        stringstream ss(version);
        string str;
        while (getline(ss, str, '.')) {
            vct.emplace_back(strtol(str.c_str(), 0, 10));
        }
    }
    
    int compareVersion(string version1, string version2) {
        vector<int> vct1;
        split(vct1, version1);
        int n1 = vct1.size();
        
        vector<int> vct2;
        split(vct2, version2);
        int n2 = vct2.size();
        
        for (int i = 0; i < n1 and i < n2; i++) {
            if (vct1[i] < vct2[i]) {
                return -1;
            } else if (vct1[i] > vct2[i]) {
                return 1;
            } else {
                // do nothing
            }
        }
        
        if (n1 < n2) {
            for (int i = n1; i < n2; i++) {
                if (vct2[i] > 0) {
                    return -1;
                }
            }
            return 0;
        } else if (n1 > n2) {
            for (int i = n2; i < n1; i++) {
                if (vct1[i] > 0) {
                    return 1;
                }
            }
            return 0;
        } else {
            return 0;
        }
    }
};
