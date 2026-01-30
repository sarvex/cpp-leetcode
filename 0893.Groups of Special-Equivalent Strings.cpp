/**
 * @brief Count distinct groups by sorting odd/even indexed characters
 * @intuition Strings are equivalent if odd-position chars and even-position chars match when sorted
 * @approach For each word, separate chars at odd and even indices, sort each group,
 *           concatenate as key. Count unique keys.
 * @complexity Time: O(n * k log k), Space: O(n * k)
 */
class Solution final {
public:
    [[nodiscard]] static auto numSpecialEquivGroups(
        const std::vector<std::string>& words) -> int {
        std::unordered_set<std::string> groups;
        
        for (const auto& word : words) {
            std::string odd, even;
            for (std::size_t i = 0; i < word.size(); ++i) {
                if (i & 1) {
                    odd += word[i];
                } else {
                    even += word[i];
                }
            }
            std::ranges::sort(odd);
            std::ranges::sort(even);
            groups.insert(odd + even);
        }
        return static_cast<int>(groups.size());
    }
};
