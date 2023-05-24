class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        r1 = v1;
        r2 = v2;
        f1 = f2 = 0;
        n1 = v1.size();
        n2 = v2.size();
        t = 0;
    }

    int next() {
        if (f1 == n1) {
            int ret = r2[f2];
            f2 += 1;
            return ret;
        } else if (f2 == n2) {
            int ret = r1[f1];
            f1 += 1;
            return ret;
        } else {
            if (t == 0) {
                int ret = r1[f1];
                f1 += 1;
                t = 1;
                return ret;
            } else {
                int ret = r2[f2];
                f2 += 1;
                t = 0;
                return ret;
            }
        }
    }

    bool hasNext() {
        return f1 != n1 or f2 != n2;
    }
    
    int f1;
    int f2;
    int n1;
    int n2;
    int t;
    vector<int> r1;
    vector<int> r2;
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */
