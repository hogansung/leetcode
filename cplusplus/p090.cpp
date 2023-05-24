class Solution {
public:
    void dfs(vector<vector<int>>& ret, vector<int>& vct,
             const vector<int>& valLst, vector<int>& cntLst,
             int t, const int n) {
        if (t == n) {
            ret.emplace_back(vct);
        } else {
            dfs(ret, vct, valLst, cntLst, t+1, n);
            if (cntLst[t] > 0) {
                cntLst[t] -= 1;
                vct.emplace_back(valLst[t]);
				dfs(ret, vct, valLst, cntLst, t, n);                
                cntLst[t] += 1;
                vct.pop_back();
            }
        }
    }
    
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) {
            return vector<vector<int>>();
        } else {        
            sort(nums.begin(), nums.end());

            vector<int> valLst;
            vector<int> cntLst;
            int val = nums[0];
            int cnt = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == val) {
                    cnt += 1;
                } else {
					valLst.emplace_back(val);
                    cntLst.emplace_back(cnt);
                    val = nums[i];
                    cnt = 1;
                }
            }
            valLst.emplace_back(val);
            cntLst.emplace_back(cnt);
            
            vector<vector<int>> ret;
            vector<int> vct;
            dfs(ret, vct, valLst, cntLst, 0, valLst.size());
            return ret;
        }
    }
};
