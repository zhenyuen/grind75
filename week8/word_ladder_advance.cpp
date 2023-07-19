#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

typedef std::unordered_map<std::string, std::vector<std::string>> Combinations;
typedef std::unordered_set<std::string> Visited;

class Solution {
public:
    int ladderLength(std::string beginWord, std::string endWord, std::vector<std::string>& wordList) {
        if (std::find(wordList.begin(), wordList.end(), endWord) == wordList.end()) return 0;

        int l = beginWord.size();

        Combinations comb;
        for (auto &w: wordList) {
            for (int i = 0; i < l; i++) {
                auto key = w;
                key[i] = '*';
                comb[std::move(key)].push_back(w);
            }
        }

        std::queue<std::pair<std::string, int>> q;
        q.push({beginWord, 1});

        Visited visited = {{beginWord, true}};
        
        while (!q.empty()) {
            auto [word, level] = q.front(); q.pop();
            for (int i = 0; i < l; i++) {
                auto temp = word; temp[i] = '*';

                for (auto &w: comb[temp]) {
                    if (w == endWord) {
                        return level + 1;
                    }

                    if (visited.find(w) == visited.end()) {
                        visited.insert(w);
                        q.push({w, level + 1});
                    }
                }
                comb[temp] = {};
            }
        }
        return 0;
    }
};