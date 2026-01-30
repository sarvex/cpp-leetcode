/**
 * @brief Check binary representations as substrings
 * @intuition Only need to check n down to n/2+1; smaller values are substrings of larger
 * @approach Convert each number to binary string and check if substring exists
 * @complexity Time: O(n * |s|), Space: O(log n)
 */
class Solution final {
public:
    [[nodiscard]] static bool queryString(const string& s, const int n) {
        if (n > 1000) {
            return false;
        }
        for (int i = n; i > n / 2; --i) {
            string b = bitset<32>(i).to_string();
            b = b.substr(b.find_first_not_of('0'));
            if (s.find(b) == string::npos) {
                return false;
            }
        }
        return true;
    }
};
