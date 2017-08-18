class Solution {
public:
    int magicalString(int n) {
        vector<int> vct = {1, 2, 2};
        int idx = 2;
        int val = 1;
        while (vct.size() < n) {
            for (int i = 0; i < vct[idx]; i++) {
                vct.push_back(val);
            }
            idx += 1;
            val = 3 - val;
        }
        
        int sum = 0;
        for (int i = 0; i < n; i++) {
            if (vct[i] == 1) {
                sum += 1;
            }
        }
        return sum;
    }
};
