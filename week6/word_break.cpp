#include <string>
#include <vector>
#include <unordered_set>

class Solution {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> words (wordDict.begin(), wordDict.end());
        std::vector<bool> dp (s.size() + 1, false);

        dp[0] = true;

        for (int i = 1; i <= s.size(); i++) {
            for (int j = 0; j < i; j++) {
                auto ss = s.substr(j, i - j);
                if (dp[j] && words.find(ss) != words.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[s.size()];
    }
};