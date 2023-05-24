public class Solution {
    final int INF = 1000000000;
    
    public int findRadius(int[] houses, int[] heaters) {
        int n = houses.length;
        int m = heaters.length;
        
        Arrays.sort(heaters);
        
        int mmax = 0;
        for (int i = 0; i < n; i++) {
            int idx = Arrays.binarySearch(heaters, houses[i]);
            if (idx < 0) {
                idx = -idx - 1;
                int lb = (idx == 0) ?INF :houses[i]-heaters[idx-1];
                int rb = (idx == m) ?INF :heaters[idx]-houses[i];
                mmax = Math.max(mmax, Math.min(lb, rb));
            }
        }
        return mmax;
    }
}
