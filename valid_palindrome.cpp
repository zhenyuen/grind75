#include <string>


class Solution {
public:
    bool isPalindrome(std::string s) {
        if (s.size() == 1) return true;
        
        char l_i = 0, r_i = s.size() - 1;
        
        while (true) {
            while (l_i < s.size() - 1 && !std::isalnum(s[l_i])) l_i++;
            while (r_i > 0 && !std::isalnum(s[r_i])) r_i--;

            if (l_i > r_i) break;

            if (std::tolower(s[l_i]) != std::tolower(s[r_i])) {
                return false;
            }
            l_i++;
            r_i--;
        }
        return true;
    }
};


class Solution {
public:
    bool isPalindrome(std::string s) {
        int l_i = 0, r_i = s.size() - 1;
        while (l_i <= r_i) {
            if (!std::isalnum(s[l_i])) {
                l_i++;
                continue;
            }
            if (!std::isalnum(s[r_i])) {
                r_i--;
                continue;
            }
            if (std::tolower(s[l_i]) != std::tolower(s[r_i])) {
                return false;
            } else {
                l_i++;
                r_i--;
            }
        }
        return true;
    }
};