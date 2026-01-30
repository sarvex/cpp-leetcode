/**
 * @brief Find longest uncommon subsequence between two strings
 * @intuition If strings differ, longer one is its own uncommon subsequence
 * @approach If strings are equal, no uncommon subsequence exists (-1).
 *           Otherwise, the longer string itself is uncommon to the other.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto findLUSlength(const string& a, const string& b) -> int {
        return a == b ? -1 : static_cast<int>(max(a.size(), b.size()));
    }
};
