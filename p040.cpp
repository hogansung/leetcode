class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
      const vector<int>& valLst, vector<int>& cntLst, 
      const int n, int flag, int target) {
        if (target == 0) {
            ret.emplace_back(vct);
        } else if (flag == n) {
            // do nothing
        } else {
            if (valLst[flag] <= target and cntLst[flag] > 0) {
                vct.push_back(valLst[flag]);
                cntLst[flag] -= 1;
                dfs(ret, vct, valLst, cntLst, n, flag, target-valLst[flag]);
                vct.pop_back();
                cntLst[flag] += 1;
            }
            dfs(ret, vct, valLst, cntLst, n, flag+1, target);
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n = candidates.size();
        if (n == 0) {
            return vector<vector<int>>();
        } else {
            sort(candidates.begin(), candidates.end());
            
            vector<int> valLst;
            vector<int> cntLst;
            int val = candidates[0];
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (candidates[i] == val) {
                    cnt += 1;
                } else {
                    valLst.push_back(val);
                    cntLst.push_back(cnt);
                    val = candidates[i];
                    cnt = 1;
                }
            }
            valLst.push_back(val);
            cntLst.push_back(cnt);
            
            vector<vector<int>> ret;
            vector<int> vct;
            dfs(ret, vct, valLst, cntLst, valLst.size(), 0, target);
            return ret;
        }
    }
};
