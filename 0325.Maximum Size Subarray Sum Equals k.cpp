/**
 * @brief Find maximum length subarray with sum equal to k
 * @intuition Use prefix sum and hash map to find subarrays with target sum
 * @approach Store first occurrence of each prefix sum, find s - k in map
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int maxSubArrayLen(const vector<int>& nums, int k) {
        unordered_map<long long, int> firstOccurrence{{0, -1}};
        int ans = 0;
        long long prefixSum = 0;
        
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            prefixSum += nums[i];
            if (firstOccurrence.contains(prefixSum - k)) {
                ans = max(ans, i - firstOccurrence[prefixSum - k]);
            }
            if (!firstOccurrence.contains(prefixSum)) {
                firstOccurrence[prefixSum] = i;
            }
        }
        return ans;
    }
};
