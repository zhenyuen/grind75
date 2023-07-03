// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l = 1, r = n;

        while (l <= r) {
            int pivot = l + (r - l) / 2;
            if (isBadVersion(pivot)) {
                if (pivot == 1) return pivot;
                if (not isBadVersion(pivot - 1)) return pivot;
                r = pivot - 1;
            } else {
                l = pivot + 1;
            }
        }
        return 1;
    }
};