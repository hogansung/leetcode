class Solution {
public:
    int smallestFactorization(int a) {
        if (a == 1) {
            return 1;
        } else {
            int factor = 9;
            vector<int> vct;
            while (a != 1 and factor > 1) {
                while (a % factor == 0) {
                    a /= factor;
                    vct.push_back(factor);
                }
                factor -= 1;
            }

            sort(vct.begin(), vct.end());

            long long ret = 0;
            for (auto v : vct) {
                ret = ret * 10 + v;
            }

            if (a != 1 or ret > INT_MAX) {
                return 0;
            } else {
                return ret;
            } 
        }
    }
};
