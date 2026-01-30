/**
 * @brief Find words matching bijective character mapping pattern
 * @intuition Word matches pattern if there's 1-to-1 mapping between characters
 * @approach For each word, check if character mapping is bijective: each word char
 *           maps to unique pattern char and vice versa.
 * @complexity Time: O(n * k), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto findAndReplacePattern(
        const std::vector<std::string>& words, const std::string& pattern)
        -> std::vector<std::string> {
        auto matches = [](const std::string& s, const std::string& t) -> bool {
            std::array<int, 128> m1{}, m2{};
            for (std::size_t i = 0; i < s.size(); ++i) {
                if (m1[s[i]] != m2[t[i]]) return false;
                m1[s[i]] = static_cast<int>(i) + 1;
                m2[t[i]] = static_cast<int>(i) + 1;
            }
            return true;
        };
        
        std::vector<std::string> ans;
        for (const auto& word : words) {
            if (matches(word, pattern)) {
                ans.push_back(word);
            }
        }
        return ans;
    }
};
