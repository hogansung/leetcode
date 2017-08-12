class Solution {
public:
    int calArea(pair<int,int> tr, pair<int,int> bl) {
        if (tr.first >= bl.first and tr.second >= bl.second) {
            return (tr.first - bl.first) * (tr.second - bl.second);
        } else {
            return 0;
        }
    }
    
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        return calArea(make_pair(C, D), make_pair(A, B)) +
               calArea(make_pair(G, H), make_pair(E, F)) -
               calArea(make_pair(min(C, G), min(D, H)), make_pair(max(A, E), max(B, F)));
    }
};
