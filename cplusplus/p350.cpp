class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        unordered_map<int,int> um1;
        for (int i = 0; i < n1; i++) {
            um1[nums1[i]] += 1;
        }
        
        int n2 = nums2.size();
        unordered_map<int,int> um2;
        for (int i = 0; i < n2; i++) {
            um2[nums2[i]] += 1;
        }
        
        vector<int> ret;
        for (auto p : um1) {
            if (um2.find(p.first) != um2.end()) {
                int mmin = min(p.second, um2[p.first]);
                for (int i = 0; i < mmin; i++) {
                    ret.push_back(p.first);
                }
            }
        }
        return ret;
    }
};
