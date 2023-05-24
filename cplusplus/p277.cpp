// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        int idx = 0;
        for (int i = 1; i < n; i++) {
            if (knows(idx, i) == true) {
                idx = i;
            }
        }
        
        bool suc = true;
        for (int i = 0; i < idx; i++) {
            suc &= !knows(idx, i);
        }
        
        for (int i = 0; i < n; i++) {
            suc &= knows(i, idx);
        }
        
        if (suc == true) {
            return idx;
        } else {
            return -1;
        }
    }
};
