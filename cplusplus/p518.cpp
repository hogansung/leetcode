class Solution {
public:
    int dp(int amount, int t, const int n,
           vector<int>& coins, vector<vector<int>>& rcd) {
        if (amount == 0) {
            return 1;
        } else if (t == n) {
            return 0;
        } else if (rcd[t][amount] != -1) {
            return rcd[t][amount];
        } else {
            int sum = 0;
            for (int i = t; i < n; i++) {
                if (amount >= coins[i]) {
                    sum += dp(amount - coins[i], i, n, coins, rcd);
                }
            }
            return rcd[t][amount] = sum;
        }
    }
    
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> rcd(n, vector<int>(amount+1, -1));
        return dp(amount, 0, n, coins, rcd); 
    }
};
