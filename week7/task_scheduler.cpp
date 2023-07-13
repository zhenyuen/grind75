#include <unordered_map>
#include <vector>

class Solution {
public:
    int leastInterval(std::vector<char>& tasks, int n) {
        std::unordered_map<char, int> counter;
        int max_freq = 0;
        for (char t: tasks) {
            int i = t - 'A';
            counter[i]++;
            max_freq = std::max(max_freq, counter[i]);
        }

        int max_freq_count = 0;
        for (auto [c, count]: counter) {
            if (count == max_freq) max_freq_count++;
        }

        int sol = (max_freq - 1) * (n + 1) + max_freq_count;
        int task_count = tasks.size();
        return std::max(sol, task_count);
    }
};