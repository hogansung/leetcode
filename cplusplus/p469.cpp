class Solution {
public:
    double cross(vector<int>& p1, vector<int>& p2, vector<int>& p3) {
        int pa_x = p2[0] - p1[0];
        int pa_y = p2[1] - p1[1];
        int pb_x = p3[0] - p2[0];
        int pb_y = p3[1] - p2[1];
        return pa_x * pb_y - pb_x * pa_y;
    }
    
    bool isConvex(vector<vector<int>>& points) {
        int n = points.size();
        bool lz = false;
        bool sz = false;
        for (int i = 0; i < n; i++) {
            double val = cross(points[i], points[(i+1)%n], points[(i+2)%n]);
            if (val < 0) {
                sz = true;
            } else if (val > 0) {
                lz = true;
            }
        }
        return sz ^ lz;
    }
};
