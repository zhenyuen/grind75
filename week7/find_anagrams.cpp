#include <vector>
#include <string>

class Solution {
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        if (s.size() < p.size()) return {};
        
        std::vector<int> p_count (26, 0);
        std::vector<int> initial (26, 0);
        std::vector<int> sol;

        for (char c: p) p_count[int(c - 'a')]++;

        for (int i = 0; i < p.size(); i++) initial[int(s[i] - 'a')]++;

        if (compare(p_count, initial)) sol.push_back(0);

        for (int i = p.size(), l = 0; i < s.size(); i++, l++) {
            initial[int(s[l] - 'a')]--;
            initial[int(s[i] - 'a')]++;
            if (compare(p_count, initial)) sol.push_back(l + 1);
        }

        return sol;
    }

    bool compare(std::vector<int> a, std::vector<int> b) {
        for (int i = 0; i < 26; i++) {
            if (a[i] != b[i]) return false;
        }
        return true;
    }
};