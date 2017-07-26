class Solution {
public:
    vector<int> calConcave(vector<int>& nums, double x_split,
                           int a, int b, int c) {
        int n = nums.size();
        
        // finding starting and ending points
        int l_st, r_st, l_ed, r_ed;
        if (nums.back() <= x_split) {
            l_st = n-1;
            l_ed = 0;
            r_st = r_ed = -1;
        } else if (nums.front() > x_split) {
            r_st = 0;
            r_ed = n-1;
            l_st = l_ed = -1;
        } else {
            l_st = l_ed = 0;
            r_st = r_ed = n-1;
            while (nums[l_st + 1] <= x_split) {
                l_st += 1;
            }
            while (nums[r_st - 1] > x_split) {
                r_st -= 1;
            }
        }
        
        vector<int> ret;
        while (l_st != -1 and r_st != -1 and 
               l_st >= l_ed and r_st <= r_ed) {
            if (x_split - nums[l_st] < nums[r_st] - x_split) {
                ret.push_back(a*nums[l_st]*nums[l_st] + 
                              b*nums[l_st] + c);
                l_st -= 1;
            } else {
                ret.push_back(a*nums[r_st]*nums[r_st] + 
                              b*nums[r_st] + c);
                r_st += 1;
            }
        }
        while (l_st != -1 and l_st >= l_ed) {
            ret.push_back(a*nums[l_st]*nums[l_st] + 
                          b*nums[l_st] + c);
            l_st -= 1;
        }
        while (r_st != -1 and r_st <= r_ed) {
            ret.push_back(a*nums[r_st]*nums[r_st] + 
                          b*nums[r_st] + c);
            r_st += 1;
        }
        
        return ret;
    }
    
    vector<int> calConvex(vector<int>& nums, double x_split,
                          int a, int b, int c) {
        int n = nums.size();
        
        // finding starting and ending points
        int l_st, r_st, l_ed, r_ed;
        if (nums.back() <= x_split) {
            l_st = 0;
            l_ed = n-1;
            r_st = r_ed = -1;
        } else if (nums.front() > x_split) {
            r_st = n-1;
            r_ed = 0;
            l_st = l_ed = -1;
        } else {
            l_st = l_ed = 0;
            r_st = r_ed = n-1;
            while (nums[l_ed + 1] <= x_split) {
                l_ed += 1;
            }
            while (nums[r_ed - 1] > x_split) {
                r_ed -= 1;
            }
        }
        
        vector<int> ret;
        while (l_st != -1 and r_st != -1 and 
               l_st <= l_ed and r_st >= r_ed) {
            if (x_split - nums[l_st] > nums[r_st] - x_split) {
                ret.push_back(a*nums[l_st]*nums[l_st] + 
                              b*nums[l_st] + c);
                l_st += 1;
            } else {
                ret.push_back(a*nums[r_st]*nums[r_st] + 
                              b*nums[r_st] + c);
                r_st -= 1;
            }
        }
        while (l_st != -1 and l_st <= l_ed) {
            ret.push_back(a*nums[l_st]*nums[l_st] + 
                          b*nums[l_st] + c);
            l_st += 1;
        }
        while (r_st != -1 and r_st >= r_ed) {
            ret.push_back(a*nums[r_st]*nums[r_st] + 
                          b*nums[r_st] + c);
            r_st -= 1;
        }
        
        return ret;
    }
    
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        int n = nums.size();
        if (n == 0) {
            return vector<int>();
        } else if (a < 0) {
            double x_split = -0.5 * b / a;
            return calConvex(nums, x_split, a, b, c);
        } else if (a > 0) {
            double x_split = -0.5 * b / a;
            return calConcave(nums, x_split, a, b, c);
        } else if (b < 0) {
            vector<int> ret;
            for (int i = n-1; i >= 0; i--) {
                ret.push_back(b * nums[i] + c);
            }
            return ret;
        } else if (b > 0) {
            vector<int> ret;
            for (int i = 0; i < n; i++) {
                ret.push_back(b * nums[i] + c);
            }
            return ret;
        } else {
            return vector<int>(n, c);
        }
    }
};
