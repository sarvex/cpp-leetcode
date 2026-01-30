/**
 * @brief Compare array with its sorted version
 * @intuition Count positions where height differs from sorted order
 * @approach Sort a copy, count mismatches with original
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int heightChecker(const vector<int>& heights) {
        vector<int> expected = heights;
        sort(expected.begin(), expected.end());
        int ans = 0;
        for (size_t i = 0; i < heights.size(); ++i) {
            ans += heights[i] != expected[i];
        }
        return ans;
    }
};
