class Solution {
public:
    const int INF = 10000;
    
    int minDistance(string word1, string word2) {
        int len1 = word1.length();
        int len2 = word2.length();
        
        vector<vector<int>> rcd(2, vector<int>(len2+1, INF));
        rcd[0][0] = 0;
        for (int i = 0; i <= len1; i++) {
            for (int j = 0; j <= len2; j++) {
                rcd[(i+1)%2][j] = INF;
            }
            
            for (int j = 0; j <= len2; j++) {
                if (i < len1 and j < len2 and 
                    word1[i] == word2[j]) {
                    rcd[(i+1)%2][j+1] = min(rcd[(i+1)%2][j+1], rcd[i%2][j]);
                }
                if (j < len2) {
                    rcd[i%2][j+1] = min(rcd[i%2][j+1], rcd[i%2][j] + 1);
                }
                if (i < len1) {
                    rcd[(i+1)%2][j] = min(rcd[(i+1)%2][j], rcd[i%2][j] + 1);
                }
            }
        }
        return rcd[len1%2][len2];
    }
};
