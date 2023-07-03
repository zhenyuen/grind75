#include <vector>

class Solution {
public:
    int longestPalindrome(string s) {
        std::vector<int> counter(int('z') - int('A') + 1, 0);
        
        for (char c: s) {
            int i = int(c) - int('A');
            counter[i]++;
        }

        int length = 0;
        bool odd = false;

        for (int i = 0; i < counter.size(); i++) {
            length += counter[i] / 2;
            if (counter[i] % 2 == 1) odd = true;
        }

        if (odd) return length * 2 + 1;
        return length * 2;
    }
};