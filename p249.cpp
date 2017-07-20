//using boost::hash_combine
template <class T>
inline void hash_combine(std::size_t& seed, T const& v)
{
    seed ^= std::hash<T>()(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

namespace std
{
    template<typename T>
    struct hash<vector<T>>
    {
        typedef vector<T> argument_type;
        typedef std::size_t result_type;
        result_type operator()(argument_type const& in) const
        {
            size_t size = in.size();
            size_t seed = 0;
            for (size_t i = 0; i < size; i++)
                //Combine the hash of the current vector with the hashes of the previous ones
                hash_combine(seed, in[i]);
            return seed;
        }
    };
}

class Solution {
public:   
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n = strings.size();
        unordered_map<vector<int>, vector<string>> um;
        
        for (int i = 0; i < n; i++) {
            int len = strings[i].length();
            vector<int> vct(len-1, 0);
            for (int j = 0; j < len-1; j++) {
                vct[j] = (strings[i][j] - strings[i][j+1] + 26) % 26;
            }
            um[vct].emplace_back(strings[i]);
        }
        
        vector<vector<string>> ret;
        for (auto p : um) {
            ret.emplace_back(p.second);
        }
        return ret;
    }
};
