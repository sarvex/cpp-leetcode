/**
 * @brief Count palindromic substrings
 * @intuition Expand around each center (single char or between chars)
 * @approach For each possible center, expand outward counting palindromes
 * @complexity Time: O(n^2), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int countSubstrings(const string& s) {
        int ans = 0;
        const int n = s.size();
        
        for (int k = 0; k < n * 2 - 1; ++k) {
            int i = k / 2;
            int j = (k + 1) / 2;
            while (i >= 0 && j < n && s[i] == s[j]) {
                ++ans;
                --i;
                ++j;
            }
        }
        return ans;
    }
};
