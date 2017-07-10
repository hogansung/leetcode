class Solution {
public:
    int findComplement(int num) {    
        for (int i = 0; i < 31; i++) {
            int val = (1 << i);
            if (num < val) {
                break;
            } else {
                num ^= val;
            }
        }
        return num;
    }
};
