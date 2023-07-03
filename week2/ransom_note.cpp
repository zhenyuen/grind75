// #include <unordered_map>
#include <vector>
// class Solution {
// public:
//     bool canConstruct(string ransomNote, string magazine) {
//         if (ransomNote.size() > magazine.size()) return false;

//         std::unordered_map<char, int> counter;

//         for (char c: magazine) counter[c]++;

//         for (char c: ransomNote) {
//             if (counter.find(c) != counter.end() and counter[c] > 0) {
//                 counter[c]--;
//             } else {
//                 return false;
//             }
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if (ransomNote.size() > magazine.size()) return false;

        std::vector<int> counter(26, 0);

        for (char c: magazine) {
            int i = int(c) - int('a');
            counter[i]++;
        }

        for (char c: ransomNote) {
            int i = int(c) - int('a');
            if (counter[i] > 0) {
                counter[i]--;
            } else {
                return false;
            }
        }
        return true;
    }
};