class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        unordered_set<int> us1;
        for (int i = 0; i < n1; i++) {
            us1.emplace(nums1[i]);
        }
        
        int n2 = nums2.size();
        unordered_set<int> us2;
        for (int i = 0; i < n2; i++) {
            us2.emplace(nums2[i]);
        }
        
        vector<int> ret;
        for (auto v : us1) {
            if (us2.find(v) != us2.end()) {
                ret.emplace_back(v);
            }
        }
        return ret;
    }
};
