/**
 * @brief Find k pairs with smallest sums from two sorted arrays
 * @intuition Use min-heap to track next smallest pair candidates
 * @approach Start with (i,0) pairs, expand by incrementing second index
 * @complexity Time: O(k log k), Space: O(k)
 */
class Solution final {
public:
    [[nodiscard]] static auto kSmallestPairs(const std::vector<int>& nums1,
                                              const std::vector<int>& nums2,
                                              int k) -> std::vector<std::vector<int>> {
        const auto m = static_cast<int>(nums1.size());
        const auto n = static_cast<int>(nums2.size());

        auto cmp = [&](const std::pair<int, int>& a, const std::pair<int, int>& b) {
            return nums1[a.first] + nums2[a.second] > nums1[b.first] + nums2[b.second];
        };

        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < std::min(k, m); ++i) {
            pq.emplace(i, 0);
        }

        std::vector<std::vector<int>> ans;
        while (k-- > 0 && !pq.empty()) {
            auto [x, y] = pq.top();
            pq.pop();
            ans.push_back({nums1[x], nums2[y]});
            if (y + 1 < n) {
                pq.emplace(x, y + 1);
            }
        }

        return ans;
    }
};
