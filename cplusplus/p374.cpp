/* The guess API is defined in the parent class GuessGame.
   @param num, your guess
   @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
      int guess(int num); */

public class Solution extends GuessGame {
    public int guessNumber(int n) {
        long l = 1;
        long r = n;
        while (l < r) {
            int m = (int)((l + r) / 2);
            int ret = guess(m);
            if (ret == +1) {
                l = m+1;
            } else {
                r = m;
            }
        }
        return (int)l;
    }
}
