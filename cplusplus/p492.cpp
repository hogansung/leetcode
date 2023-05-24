class Solution {
public:
    vector<int> constructRectangle(int area) {
        int val = 1;
        for (int i = 1; i <= sqrt(area); i++) {
            if (area % i == 0) {
                val = i;
            }
        }
        
        vector<int> ret = {area/val, val};
        return ret;
    }
};
