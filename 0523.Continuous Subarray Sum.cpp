/**
 * @brief Check if subarray sum is multiple of k
 * @intuition If prefix[i] % k == prefix[j] % k, then sum(i+1..j) is divisible by k
 * @approach Track first occurrence of each prefix sum modulo k. If same remainder seen
 *           at positions > 1 apart, found valid subarray of length >= 2.
 * @complexity Time: O(n), Space: O(min(n, k))
 */
class Solution final {
public:
    [[nodiscard]] static auto checkSubarraySum(const vector<int>& nums, int k) -> bool {
        unordered_map<int, int> firstOccurrence{{0, -1}};
        int prefixSum = 0;
        
        for (int i = 0; i < static_cast<int>(nums.size()); ++i) {
            prefixSum = (prefixSum + nums[i]) % k;
            if (!firstOccurrence.contains(prefixSum)) {
                firstOccurrence[prefixSum] = i;
            } else if (i - firstOccurrence[prefixSum] > 1) {
                return true;
            }
        }
        return false;
    }
};
