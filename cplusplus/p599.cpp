class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size();
        int n2 = list2.size();
        
        int mmin = INT_MAX;
        vector<string> ret;
        for (int i = 0; i < n1; i++) {
            for (int j = 0; j < n2; j++) {
                if (list1[i] == list2[j]) {
                    if (mmin > i + j) {
                        mmin = i + j;
                        ret = vector<string>(1, list1[i]);
                    } else if (mmin == i + j) {
                        ret.emplace_back(list1[i]);
                    }
                }
            }
        }
        return ret;
    }
};
