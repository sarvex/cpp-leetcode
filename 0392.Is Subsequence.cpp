/**
 * @brief Check if s is a subsequence of t
 * @intuition Two pointers: advance s pointer only when characters match
 * @approach Traverse t, increment s pointer on match, check if all s consumed
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto isSubsequence(const std::string& s, const std::string& t) -> bool {
        const auto m = static_cast<int>(s.size());
        const auto n = static_cast<int>(t.size());
        int i = 0;

        for (int j = 0; i < m && j < n; ++j) {
            if (s[i] == t[j]) {
                ++i;
            }
        }

        return i == m;
    }
};
