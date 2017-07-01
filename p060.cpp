class Solution {
public:
    int findIdx(vector<bool>& used, int t, const int n) {
        for (int i = 0; i < n; i++) {
            if (t == 0) {
                if (used[i] == false) {
                    used[i] = true;
                    return i;
                }
            } else if (used[i] == false) {
                t -= 1;
            }
        }
        assert(false);
    }

    string getPermutation(int n, int k) {

        vector<int> stairs(n+1, 1);
        for (int i = 1; i < n+1; i++) {
            stairs[i] = stairs[i-1] * i;
        }
        k = (k-1) % stairs[n];
        
        string ret;
        vector<bool> used(n, false);
        for (int i = 0; i < n; i++) {
            int idx = k / stairs[n-1-i];
            int val = findIdx(used, idx, n);
            ret.push_back(val + 1 + '0');
            k %= stairs[n-1-i];
        }
        return ret;
    }
};
