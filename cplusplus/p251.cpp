lass Vector2D {
public:
    void update() {
        while (cm == m and cn < n) {
            m = rcd[cn].size();
            cn += 1;
            cm = 0;
        }
    }
    
    Vector2D(vector<vector<int>>& vec2d) {
        rcd = vec2d;
        n = vec2d.size();
        m = 0;
        cn = 0;
        cm = 0;
    }

    int next() {
        int ret = rcd[cn-1][cm];
        cm += 1;
        return ret;
    }

    bool hasNext() {
        update();
        if (cm == m) {
            return false;
        } else {
            return true;
        }
    }
    
    int cn;
    int cm;
    int n;
    int m;
    vector<vector<int>> rcd;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
