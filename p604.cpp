class StringIterator {
public:
    StringIterator(string compressedString) {
        rcd = compressedString;
        len = compressedString.length();
        flag = 0;
        cnt = 0;
    }
    
    void update() {
        if (cnt == 0) {
            chr = rcd[flag];
            flag += 1;
            string str;
            while (flag < len) {
                if (rcd[flag] >= '0' and 
                    rcd[flag] <= '9') {
                    str.push_back(rcd[flag]);
                    flag += 1;
                } else {
                    break;
                }
            }
            cnt = strtol(str.c_str(), 0, 10);
        }
    }
    
    char next() {
        if (flag == len and cnt == 0) {
            return ' ';
        } else if (flag < len and cnt == 0) {
            update();
        }
        cnt -= 1;
        return chr;
    }
    
    bool hasNext() {
        if (flag == len and cnt == 0) {
            return false;
        } else if (flag < len and cnt == 0) {
            update();
        }
        return cnt > 0;
    }
    
    string rcd;
    int flag;
    int len;
    int cnt;
    char chr;
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
