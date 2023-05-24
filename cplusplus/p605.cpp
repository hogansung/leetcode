class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size and n; i++) {
            if (flowerbed[i] == 0 and
                (i == 0 or flowerbed[i-1] == 0) and 
                (i == size-1 or flowerbed[i+1] == 0)) {
                flowerbed[i] = 1;
                n -= 1;
            }
        }
        return n == 0;
    }
};
