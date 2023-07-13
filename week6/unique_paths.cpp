class Solution {
public:
    int uniquePaths(int m, int n) {
        int k = m + n - 2;
        int l = m - 1;
        int r = n - 1;
        long res = 1;

        while (k > 1 || l > 1 || r > 1) {

            while ( l > 1 && res % l == 0 ) {res /= l; l--;};
            while ( r > 1 && res % r == 0 ) {res /= r; r--;};

            if (k > 1) {
                res *= k; k--;
            }
            
        }

        return res;

    }
};