/**
 * @brief Find k-th smallest pair distance using binary search
 * @intuition Binary search on distance value, count pairs with distance <= mid
 * @approach Sort array, binary search distance range, count pairs efficiently
 * @complexity Time: O(n log n + n log W) where W is max distance, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int smallestDistancePair(std::vector<int>& nums, const int k) {
        std::ranges::sort(nums);
        int left = 0;
        int right = nums.back() - nums.front();
        
        while (left < right) {
            const int mid = (left + right) >> 1;
            if (countPairs(nums, mid) >= k) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }

private:
    [[nodiscard]] static int countPairs(const std::vector<int>& nums, const int maxDist) {
        int count = 0;
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            const int target = nums[i] - maxDist;
            const auto j = std::ranges::lower_bound(nums.begin(), nums.begin() + i, target) - nums.begin();
            count += i - j;
        }
        return count;
    }
};
