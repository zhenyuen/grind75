#include <vector>
#include <string>
#include <queue>

class Solution {
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        if (digits == "") return {};

        std::vector<std::vector<char>> map (10);
        map[0] = {};
        map[1] = {};
        map[2] = {'a', 'b', 'c'};
        map[3] = {'d', 'e', 'f'}; 
        map[4] = {'g', 'h', 'i'};
        map[5] = {'j', 'k', 'l'};
        map[6] = {'m', 'n', 'o'};
        map[7] = {'p', 'q', 'r', 's'};
        map[8] = {'t', 'u', 'v'};
        map[9] = {'w', 'x', 'y', 'z'};

        std::queue<std::string> sol;
        sol.push("");

        for (auto it = digits.begin(); it != digits.end(); it++) {
            int d = *it - '0';
            int n = sol.size();
            for (int i = 0; i < n; i++) {
                auto temp = sol.front(); sol.pop();
                for (char c: map[d]) {
                    sol.push(temp + c);
                }
            }
        }

        std::vector<std::string> temp;
        while (!sol.empty()) {
            temp.push_back(sol.front());
            sol.pop();
        }
        return temp;
    }
};