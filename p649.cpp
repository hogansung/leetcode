class Solution {
public:
    string predictPartyVictory(string senate) {
        int len = senate.length();
        
        queue<int> qr;
        queue<int> qd;
        for (int i = 0; i < len; i++) {
            if (senate[i] == 'R') {
                qr.push(i);
            } else {
                qd.push(i);
            }
        }

        while (qr.size() and qd.size()) {
            for (int i = 0; i < len; i++) {
                if (senate[i] == 'R') {
                    if (qr.size() and qr.front() == i) {
                        qr.push(i);
                        qr.pop();
                        if (qd.size()) {
                            qd.pop();
                        }
                    }
                } else {
                    if (qd.size() and qd.front() == i) {
                        qd.push(i);
                        qd.pop();
                        if (qr.size()) {
                            qr.pop();
                        }
                    }
                }
            }
        }
        
        if (qr.size()) {
            return "Radiant";
        } else {
            return "Dire";
        }
    }
};
