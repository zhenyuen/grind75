#include <string>

class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int sol = 0;
        std::string ss = "";

        auto dfs = [&] (int l, int r) {
            int n = s.size();
            while (l >= 0 && r < n && s[l] == s[r]) {
                auto d = r - l + 1;
                if (d > sol) {
                    sol = d;
                    ss = s.substr(l, d);
                }
                l--; r++;
            }
        };

        for (int i = 0; i < s.size(); i++) {
            dfs(i, i);
            dfs(i, i + 1);
        }
        
        return ss;
    }
};