#include <string>

class Solution {
public:
    int myAtoi(std::string s) {
        int state = 0;
        // 0: have not found start point
        // 1: found start point, no sign
        // 2: found start point, has sign

        int res = 0;
        auto it = s.begin();
        bool is_neg = false;

        while (it != s.end() && *it == ' ') it++;

        for (;it != s.end(); it++) {
            if (state == 0) {
                if (std::isdigit(*it)) {
                    res += int (*it - '0');
                    state = 1;
                } else if (*it == '-' || *it == '+') {
                    if (*it == '-') {
                        state = 2;
                    } else {
                        state = 1;
                    }
                } else {
                    break;
                }
            } else if (state == 1 && std::isdigit(*it)) {
                auto diff = int (*it - '0');
                if ((INT_MAX - diff) / 10 < res) return INT_MAX;
                res *= 10;
                res += diff;
            } else if (state == 2 && std::isdigit(*it)) {
                auto diff = int (*it - '0');
                if ((INT_MIN + diff) / 10  > res) return INT_MIN;
                res *= 10;
                res -= diff;
            } else {
                return res;
            }
        }
        return res;
    }
};