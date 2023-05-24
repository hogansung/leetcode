// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int len = rcd.length();
        int flag = min(len, n);
        strncpy(buf, rcd.c_str(), flag);
        rcd = rcd.substr(flag, len-flag);
        
        char tmp[5];
        while (flag < n) {
            int ret = read4(tmp);
            int val = min(ret, n-flag);
            strncpy(buf + flag, tmp, val);
            rcd += string(tmp, val, ret-val);
            
            flag += val;
            if (val != 4) {
                break;
            }
        }
        return flag;
    }
    
    string rcd;
};
