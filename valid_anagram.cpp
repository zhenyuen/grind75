#include <unordered_map>
#include <string>

class Solution {
public:
    bool isAnagram(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> s_counter;

        for (const auto& c: s) s_counter[c]++;

        for (const auto& c: t) {
            if (s_counter.find(c) == s_counter.end()) return false;
            
            s_counter[c]--;

            if (s_counter[c] == 0) s_counter.erase(c);
        }


        return s_counter.size() == 0;
    }
};

class Solution {
public:
    bool isAnagram(const std::string &s, const std::string &t) {
        if (s.size() != t.size()) return false;

        std::unordered_map<char, int> s_counter, t_counter;

        for (const auto& c: s) s_counter[c]++;
        for (const auto& c: t) t_counter[c]++;

        for (const auto& [c, count]: s_counter) {
            if (t_counter.find(c) == t_counter.end()) return false;
            if (t_counter[c] != count) return false;
        }

        return true;
    }
};