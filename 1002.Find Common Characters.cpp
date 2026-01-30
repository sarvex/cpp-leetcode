/**
 * @brief Character frequency intersection
 * @intuition Track minimum frequency of each character across all words
 * @approach Maintain count array, update with minimum for each word, then extract results
 * @complexity Time: O(n * m) where n = words, m = avg word length, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::string> commonChars(const std::vector<std::string>& words) {
        std::array<int, 26> cnt{};
        std::ranges::fill(cnt, 20000);
        
        for (const auto& w : words) {
            std::array<int, 26> t{};
            for (const char c : w) {
                ++t[c - 'a'];
            }
            for (int i = 0; i < 26; ++i) {
                cnt[i] = std::min(cnt[i], t[i]);
            }
        }
        
        std::vector<std::string> ans;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < cnt[i]; ++j) {
                ans.emplace_back(1, 'a' + i);
            }
        }
        return ans;
    }
};
