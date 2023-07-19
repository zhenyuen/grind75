#include <unordered_map>
#include <string>

typedef std::unordered_map<char, int> Counter;

class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        if (s.size() == 0 || t.size() == 0) return "";
        if (s.size() < t.size()) return "";

        Counter ct;
        for (char c: t) ct[c]++;

        int required = ct.size();

        std::vector<std::pair<int, char>> filtered_s;
        filtered_s.reserve(s.size());

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            if (ct.find(c) != ct.end()) {
                filtered_s.push_back({i, c});
            }
        }

        int l = 0;
        int r = 0;
        int formed = 0;
        Counter window_counts;

        std::vector<int> ans = {INT_MAX, -1, -1};


        while (r < filtered_s.size()) {
            char c = filtered_s[r].second;
            window_counts[c]++;

            if (window_counts[c] == ct[c]) {
                formed++;
            }

            while (l <= r && formed == required) {
                char c = filtered_s[l].second;
                int end = filtered_s[r].first;
                int start = filtered_s[l].first;

                if (end - start + 1 < ans[0]) {
                    ans = {end - start + 1, start, end};
                }

                window_counts[c]--;
                if (window_counts[c] < ct[c]) {
                    formed--;
                }
                l++;
            }
            r++;
        }
        return ans[0] == INT_MAX? "" : s.substr(ans[1], ans[2] - ans[1] + 1);

    }

};