/**
 * @brief Greedy assignment to maximize advantage over opponent
 * @intuition Use smallest number that beats opponent; otherwise use smallest overall
 * @approach Sort both arrays. For each opponent value (ascending), use smallest
 *           nums1 value that beats it. If none beats it, assign smallest remaining.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto advantageCount(std::vector<int>& nums1,
                                              const std::vector<int>& nums2)
        -> std::vector<int> {
        const int n = static_cast<int>(nums1.size());
        std::vector<std::pair<int, int>> indexed;
        indexed.reserve(n);
        
        for (int i = 0; i < n; ++i) {
            indexed.emplace_back(nums2[i], i);
        }
        
        std::ranges::sort(indexed);
        std::ranges::sort(nums1);
        
        int i = 0, j = n - 1;
        std::vector<int> ans(n);
        
        for (const int v : nums1) {
            if (v <= indexed[i].first) {
                ans[indexed[j--].second] = v;
            } else {
                ans[indexed[i++].second] = v;
            }
        }
        return ans;
    }
};
