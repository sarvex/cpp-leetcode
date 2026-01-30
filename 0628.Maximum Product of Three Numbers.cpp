/**
 * @brief Find maximum product of any three numbers
 * @intuition Either three largest positives or two smallest negatives times largest positive
 * @approach Sort and compare product of three largest vs two smallest and largest
 * @complexity Time: O(n log n), Space: O(log n) for sorting
 */
class Solution final {
public:
    [[nodiscard]] static int maximumProduct(vector<int>& nums) {
        ranges::sort(nums);
        const int n = nums.size();
        const int a = nums[n - 1] * nums[n - 2] * nums[n - 3];
        const int b = nums[n - 1] * nums[0] * nums[1];
        return max(a, b);
    }
};
