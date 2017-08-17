class Solution {
public:
    string getHint(string secret, string guess) {
        int len = secret.length();
        vector<int> cnt(10, 0);
        
        int na = 0;
        int nb = 0;
        for (int i = 0; i < len; i++) {
            if (secret[i] == guess[i]) {
                na += 1;
            } else {
                if (cnt[secret[i]-'0'] < 0) {
                    nb += 1;
                }
                cnt[secret[i]-'0'] += 1;
                
                if (cnt[guess[i]-'0'] > 0) {
                    nb += 1;
                }
                cnt[guess[i]-'0'] -= 1;
            }
        }
        return to_string(na) + "A" + to_string(nb) + "B";
    }
};
