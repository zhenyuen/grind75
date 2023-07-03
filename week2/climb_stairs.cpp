// #include <unordered_map>

// class Solution {
// private:
//     std::unordered_map<int, int> cache;
// public:
//     int climbStairs(int n) {
//         if (n == 1) return 1;
//         if (n == 2) return 2;

//         if (cache.find(n) != cache.end()) return cache[n];

//         cache[n] = climbStairs(n - 1) + climbStairs(n - 2);
//         return cache[n];
//     }
// };

// #include <vector>

// class Solution {
// public:
//     int climbStairs(int n) {
//         if (n == 1) return 1;
//         if (n == 2) return 2;

//         std::vector<int> cache(n+1);

//         cache[1] = 1;
//         cache[2] = 2;

//         for (int i = 3; i <= n; i++) {
//             cache[i] = cache[i - 1] + cache[i - 2];
//         }

//         return cache[n];
//     }
// };


class Solution {
public:
    int climbStairs(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;

        int prev_1 = 2;
        int prev_2 = 1;
        int sol;

        for (int i = 3; i <= n; i++) {
            sol = prev_1 + prev_2;
            prev_2 = prev_1;
            prev_1 = sol;
        }

        return sol;
    }
};