/**
 * @brief Count distinct OR values of all subarrays
 * @intuition OR of subarray ending at i: union of (OR of subarray ending at i-1) | arr[i]
 * @approach Maintain set of all OR values for subarrays ending at current position.
 *           For each new element, OR it with all previous values and itself.
 *           Union into answer set.
 * @complexity Time: O(n * 32), Space: O(n * 32)
 */
class Solution final {
public:
    [[nodiscard]] static auto subarrayBitwiseORs(const std::vector<int>& arr) -> int {
        std::unordered_set<int> ans;
        std::unordered_set<int> current;
        
        for (const int x : arr) {
            std::unordered_set<int> next;
            for (const int y : current) {
                next.insert(x | y);
            }
            next.insert(x);
            ans.insert(next.begin(), next.end());
            current = std::move(next);
        }
        return static_cast<int>(ans.size());
    }
};
