struct SimpleHash {
    size_t operator()(const std::pair<int, int>& p) const {
        return p.first ^ p.second;
    }
};

class SnakeGame {
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int width, int height, vector<pair<int, int>> food) {
        n = height;
        m = width;
        r = c = 0;
        
        rfood = food;
        flag = 0;
        
        board = unordered_set<pair<int,int>, SimpleHash>();
        board.emplace(r, c);
        
        qloc = queue<pair<int,int>>();
        qloc.emplace(r, c);
        score = 0;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        if (direction == "U") {
            r -= 1;
        } else if (direction == "L") {
            c -= 1;
        } else if (direction == "R") {
            c += 1;
        } else if (direction == "D") {
            r += 1;
        } else {
            assert(false);
        }
        
        if (r < 0 or r >= n or c < 0 or c >= m) {
            return -1;
        } else if (flag < rfood.size() and 
                   r == rfood[flag].first and c == rfood[flag].second) {
            flag += 1;
            score += 1;
            qloc.emplace(r, c);
            board.emplace(r, c);
            return score;
        } else {
            pair<int,int> oloc = qloc.front(); qloc.pop();
            board.erase(oloc);
            if (board.find(make_pair(r, c)) != board.end()) {
                return -1;
            } else {
                qloc.emplace(r, c);
                board.emplace(r, c);
                return score;
            }
        }
    }
    
    unordered_set<pair<int,int>, SimpleHash> board;
    int n, m;
    
    vector<pair<int, int>> rfood;
    int flag;
    
    queue<pair<int,int>> qloc;    
    int r, c;
    int score;
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
