/**
 * @brief Binary search for kth missing element
 * @intuition Count missing elements up to each index; binary search for position
 * @approach Missing(i) = nums[i] - nums[0] - i; binary search for k
 * @complexity Time: O(log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int missingElement(const vector<int>& nums, const int k) {
        auto missing = [&](const int i) {
            return nums[i] - nums[0] - i;
        };
        const int n = nums.size();
        if (k > missing(n - 1)) {
            return nums[n - 1] + k - missing(n - 1);
        }
        int l = 0, r = n - 1;
        while (l < r) {
            const int mid = (l + r) >> 1;
            if (missing(mid) >= k) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return nums[l - 1] + k - missing(l - 1);
    }
};
