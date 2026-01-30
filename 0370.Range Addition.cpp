/**
 * @brief Apply range updates efficiently using difference array
 * @intuition Mark start and end+1 of each update, then prefix sum
 * @approach Difference array: add at start, subtract at end+1, cumulative sum
 * @complexity Time: O(n + k), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> getModifiedArray(const int length, 
                                                            const std::vector<std::vector<int>>& updates) {
        std::vector<int> d(length);
        
        for (const auto& e : updates) {
            const int l = e[0];
            const int r = e[1];
            const int c = e[2];
            d[l] += c;
            if (r + 1 < length) {
                d[r + 1] -= c;
            }
        }
        
        for (int i = 1; i < length; ++i) {
            d[i] += d[i - 1];
        }
        return d;
    }
};
