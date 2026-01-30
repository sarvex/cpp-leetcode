/**
 * @brief Find partition point with left max <= right min
 * @intuition Precompute suffix minimums, track prefix maximum
 * @approach Iterate while tracking max; find first point where max <= suffix min
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int partitionDisjoint(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> mi(n + 1, INT_MAX);
        for (int i = n - 1; i >= 0; --i) {
            mi[i] = min(nums[i], mi[i + 1]);
        }
        int mx = 0;
        for (int i = 1;; ++i) {
            const int v = nums[i - 1];
            mx = max(mx, v);
            if (mx <= mi[i]) {
                return i;
            }
        }
    }
};
