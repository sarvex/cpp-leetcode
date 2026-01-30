/**
 * @brief Find swap pair to equalize candy totals
 * @intuition If swap a for b, need a - b = (sumA - sumB) / 2
 * @approach Compute sums and difference. For each of Alice's candies a,
 *           calculate required b = a - diff. Check if Bob has b.
 * @complexity Time: O(n + m), Space: O(m)
 */
class Solution final {
public:
    [[nodiscard]] static auto fairCandySwap(const std::vector<int>& aliceSizes,
                                             const std::vector<int>& bobSizes)
        -> std::vector<int> {
        const int s1 = std::accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        const int s2 = std::accumulate(bobSizes.begin(), bobSizes.end(), 0);
        const int diff = (s1 - s2) >> 1;
        
        std::unordered_set<int> bobSet(bobSizes.begin(), bobSizes.end());
        
        for (const int a : aliceSizes) {
            const int b = a - diff;
            if (bobSet.contains(b)) {
                return {a, b};
            }
        }
        return {};
    }
};
