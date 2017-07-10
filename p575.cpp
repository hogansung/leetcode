class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> us;
        for (auto id : candies) {
            us.emplace(id);
        }
        return min(us.size(), candies.size()/2);
    }
};
