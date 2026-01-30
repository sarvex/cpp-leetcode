/**
 * @brief Find positions of large groups (3+ consecutive identical chars)
 * @intuition Two-pointer scan to identify groups and their boundaries
 * @approach Iterate through string, tracking start of each group. When group
 *           ends (different char or end), check if length >= 3 and record.
 * @complexity Time: O(n), Space: O(1) excluding output
 */
class Solution final {
public:
    [[nodiscard]] static auto largeGroupPositions(const std::string& s)
        -> std::vector<std::vector<int>> {
        const int n = static_cast<int>(s.size());
        std::vector<std::vector<int>> ans;
        
        int i = 0;
        while (i < n) {
            int j = i;
            while (j < n && s[j] == s[i]) {
                ++j;
            }
            if (j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            i = j;
        }
        return ans;
    }
};
