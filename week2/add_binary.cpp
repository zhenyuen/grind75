#include <vector>
#include <sstream>
#include <string>

typedef std::vector<bool> dyn_bitset;

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        if (a.size() < b.size()) std::swap(a, b);

        dyn_bitset aa, bb;
        aa.reserve(a.size());
        bb.reserve(b.size());

        for (auto it = a.rbegin(); it != a.rend(); it++) {
            aa.push_back(*it == '1'? 1 : 0);
        } 
        for (auto it = b.rbegin(); it != b.rend(); it++) {
            bb.push_back(*it == '1'? 1 : 0);
        }

        int i;
        bool carry = 0;
        for (i = 0; i < b.size(); i++) {
            auto sum = carry ^ aa[i] ^ bb[i];
            carry = (aa[i] & bb[i]) | 
                (aa[i] & carry) | 
                (bb[i] & carry); 
            aa[i] = sum;
        }

        for (; i < aa.size() and carry != 0; i++) {
            auto sum = carry ^ aa[i];
            carry = aa[i] & carry;
            aa[i] = sum;
        }

        std::stringstream ss;

        if (carry) ss << "1";

        for (auto it = aa.rbegin(); it != aa.rend(); it++) {
            ss << *it? "1" : "0";
        }

        return ss.str();
    }
};