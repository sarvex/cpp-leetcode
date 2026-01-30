/**
 * @brief Maximum chunks to sort permutation array
 * @intuition Chunk ends when max so far equals current index
 * @approach Track running max; increment count when max equals index
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int maxChunksToSorted(const std::vector<int>& arr) {
        int chunks = 0;
        int maxSoFar = 0;
        
        for (int i = 0; i < static_cast<int>(arr.size()); ++i) {
            maxSoFar = std::max(maxSoFar, arr[i]);
            chunks += (maxSoFar == i);
        }
        return chunks;
    }
};
