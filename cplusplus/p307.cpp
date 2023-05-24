class NumArray {
public:
    int _read(int idx){
        int sum = 0;
        while (idx > 0){
            sum += tree[idx];
            idx -= (idx & -idx);
        }
        return sum;
    }
    
    void _update(int idx ,int val){
        while (idx <= MaxVal){
            tree[idx] += val;
            idx += (idx & -idx);
        }
    }
    
    NumArray(vector<int> nums) {
        int n = nums.size();
        vct = vector<int>(n, 0);
        
        MaxVal = 1000000;
        tree = vector<int>(MaxVal, 0);
 
        for (int i = 0; i < n; i++) {
            update(i, nums[i]);
        }
    }
    
    void update(int i, int val) {
        _update(i+1, val-vct[i]);
        vct[i] = val;
    }
    
    int sumRange(int i, int j) {
        return _read(j+1) - _read(i);
    }
    
    vector<int> vct;
    vector<int> tree;
    int MaxVal;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
