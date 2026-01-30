/**
 * @brief Count contribution of each character to unique character count
 * @intuition Each character contributes to substrings where it appears exactly once
 * @approach For each character occurrence at index i, count substrings where it's unique:
 *           (i - prev_occurrence) * (next_occurrence - i). Use positions array per char.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto uniqueLetterString(const std::string& s) -> int {
        std::vector<std::vector<int>> d(26, std::vector<int>{-1});
        const int n = static_cast<int>(s.size());
        
        for (int i = 0; i < n; ++i) {
            d[s[i] - 'A'].push_back(i);
        }
        
        int ans = 0;
        for (auto& v : d) {
            v.push_back(n);
            for (std::size_t i = 1; i < v.size() - 1; ++i) {
                ans += (v[i] - v[i - 1]) * (v[i + 1] - v[i]);
            }
        }
        return ans;
    }
};
