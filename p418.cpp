class Solution {
public:
    int wordsTyping(vector<string>& sentence, int rows, int cols) {
        int n = sentence.size();
        
        vector<int> sum(n+1, 0);
        for (int i = 0; i < n; i++) {
            sum[i+1] = sum[i] + sentence[i].length();
        }
        
        int flag_s = 0;
        int flag_c = 0;
        int cnt = 0;
        for (int i = 0; i < rows; i++) {
            while (flag_c < cols) {
                if (flag_c + sentence[flag_s].length() > cols) { // cannot put any sentence
                    flag_c = 0;
                    break;
                } else if (flag_s == 0 and flag_c + sum[n] + n-1 <= cols) { // put multiple times
                    int times = (cols - flag_c + 1) / (sum[n] + n);
                    flag_c += (sum[n] + n) * times;
                    cnt += times;
                } else { // at least can put one sentence
                    int l = flag_s;
                    int r = n-1;
                    while (l < r) {
                        int m = (l + r) / 2 + 1;
                        if (flag_c + sum[m+1] - sum[flag_s] + (m - flag_s) <= cols) {
                            l = m;
                        } else {
                            r = m-1;
                        }
                    }

                    if (l == n-1) { // finish all sentences; restart
                        flag_c += sum[l+1] - sum[flag_s] + (l - flag_s) + 1;
                        flag_s = 0;
                        cnt += 1;
                    } else { // finish fill up one row
                        flag_s = l+1;
                        flag_c = 0;
                        break;
                    }
                }
            }
            flag_c = 0;
        }
        return cnt;
    }
};
