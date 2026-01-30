/**
 * @brief Find lexicographically smallest string after rotations/sorts
 * @intuition k=1: only rotations possible; k>=2: any permutation achievable (bubble sort)
 * @approach If k == 1, try all rotations and return smallest. If k >= 2,
 *           we can achieve any permutation, so return sorted string.
 * @complexity Time: O(n^2) for k=1, O(n log n) for k>=2, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto orderlyQueue(std::string s, int k) -> std::string {
        if (k == 1) {
            std::string ans = s;
            const int n = static_cast<int>(s.size());
            for (int i = 0; i < n - 1; ++i) {
                s = s.substr(1) + s[0];
                if (s < ans) ans = s;
            }
            return ans;
        }
        std::ranges::sort(s);
        return s;
    }
};
