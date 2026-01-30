/**
 * @brief LIS on sorted envelopes for Russian doll nesting
 * @intuition Sort by width ascending, height descending, then find LIS on height
 * @approach Sort specially to reduce to 1D LIS problem, use binary search
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxEnvelopes(std::vector<std::vector<int>>& envelopes) {
        std::ranges::sort(envelopes, [](const auto& a, const auto& b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]);
        });
        
        const int n = static_cast<int>(envelopes.size());
        std::vector<int> dp{envelopes[0][1]};
        
        for (int i = 1; i < n; ++i) {
            const int h = envelopes[i][1];
            if (h > dp.back()) {
                dp.push_back(h);
            } else {
                auto it = std::ranges::lower_bound(dp, h);
                *it = h;
            }
        }
        return static_cast<int>(dp.size());
    }
};
