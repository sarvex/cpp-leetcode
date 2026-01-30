/**
 * @brief Find longest subarray with equal 0s and 1s
 * @intuition Treat 0 as -1; equal counts means sum is 0; use prefix sum technique
 * @approach Track first occurrence of each prefix sum. When same sum seen again,
 *           subarray between has equal 0s and 1s. Update max length.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findMaxLength(const vector<int>& nums) -> int {
        unordered_map<int, int> firstOccurrence{{0, -1}};
        int ans = 0, sum = 0;
        
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            sum += nums[i] ? 1 : -1;
            if (firstOccurrence.contains(sum)) {
                ans = max(ans, i - firstOccurrence[sum]);
            } else {
                firstOccurrence[sum] = i;
            }
        }
        return ans;
    }
};
