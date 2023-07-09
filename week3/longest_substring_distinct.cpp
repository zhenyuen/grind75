#include <unordered_set>
#include <string>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        if (s.size() < 2) return s.size();
        
        int sol = 0;
        int l = 0, r;
        std::unordered_set<char> set;
        
        for (int r = l; r < s.size(); r++) {
            auto c = s[r];
            while (set.find(c) != set.end()) {
                set.erase(s[l++]);
            }
            set.insert(c);
            sol = std::max(sol, r - l + 1);
        }

        return sol;

    }
};