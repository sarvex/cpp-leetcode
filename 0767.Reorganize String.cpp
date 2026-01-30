/**
 * @brief Reorganize string so no two adjacent chars are same
 * @intuition Place most frequent chars at even indices first, then odd
 * @approach Sort by frequency, fill even positions, then odd
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::string reorganizeString(const std::string& s) {
        std::array<int, 26> counts{};
        for (const char c : s) {
            ++counts[c - 'a'];
        }
        
        const int maxCount = *std::ranges::max_element(counts);
        const int n = static_cast<int>(s.size());
        if (maxCount > (n + 1) / 2) {
            return "";
        }
        
        std::vector<std::pair<int, int>> freqs;
        for (int i = 0; i < 26; ++i) {
            if (counts[i]) {
                freqs.emplace_back(counts[i], i);
            }
        }
        std::ranges::sort(freqs, std::greater<>());
        
        std::string result(n, ' ');
        int pos = 0;
        for (const auto& [count, charIdx] : freqs) {
            for (int i = 0; i < count; ++i) {
                result[pos] = static_cast<char>('a' + charIdx);
                pos += 2;
                if (pos >= n) {
                    pos = 1;
                }
            }
        }
        return result;
    }
};
