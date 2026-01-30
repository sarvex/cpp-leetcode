/**
 * @brief Minimum increments to make all elements unique
 * @intuition Sort array; each element must be at least previous + 1
 * @approach Track minimum allowed value; count difference when adjustment needed
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int minIncrementForUnique(vector<int>& nums) {
        ranges::sort(nums);
        int ans = 0, y = -1;
        for (const int x : nums) {
            y = max(y + 1, x);
            ans += y - x;
        }
        return ans;
    }
};
