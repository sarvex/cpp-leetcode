/**
 * @brief Find longest chain of pairs where (a,b) < (c,d) means b < c
 * @intuition Sort by end value, greedily select non-overlapping pairs
 * @approach Sort by second element, select pairs that don't overlap
 * @complexity Time: O(n log n), Space: O(log n) for sorting
 */
class Solution final {
public:
    [[nodiscard]] static int findLongestChain(vector<vector<int>>& pairs) {
        ranges::sort(pairs, {}, [](const auto& p) { return p[1]; });
        int ans = 0;
        int pre = INT_MIN;
        
        for (const auto& p : pairs) {
            if (pre < p[0]) {
                pre = p[1];
                ++ans;
            }
        }
        return ans;
    }
};
