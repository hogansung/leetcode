class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        reverse(digits.begin(), digits.end());
        
        int n = digits.size();
        int val = 1;
        for (int i = 0; i < n; i++) {
            val += digits[i];
            digits[i] = val % 10;
            val /= 10;
        }
        
        if (val) {
            digits.push_back(val);
        }
        
        reverse(digits.begin(), digits.end());
        return digits;
    }
};
