/**
 * @brief Generate n-bit Gray code sequence
 * @intuition Gray code formula: i XOR (i >> 1) ensures adjacent codes differ by 1 bit
 * @approach Iterate through all 2^n numbers applying the Gray code formula
 * @complexity Time: O(2^n), Space: O(1) excluding output
 */
class Solution final {
public:
    [[nodiscard]] static auto grayCode(const int n) -> vector<int> {
        vector<int> result;
        result.reserve(1 << n);
        
        for (int i = 0; i < (1 << n); ++i) {
            result.push_back(i ^ (i >> 1));
        }
        return result;
    }
};
