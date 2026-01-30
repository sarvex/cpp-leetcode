/**
 * @brief Count subarrays with sum k using prefix sum hash map
 * @intuition If prefix[j] - prefix[i] = k, subarray (i,j] has sum k
 * @approach Track prefix sum frequencies; for each sum s, add count of (s-k) to answer
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int subarraySum(const vector<int>& nums, const int k) {
        unordered_map<int, int> prefixCount{{0, 1}};
        int ans = 0;
        int sum = 0;
        
        for (const int x : nums) {
            sum += x;
            ans += prefixCount[sum - k];
            ++prefixCount[sum];
        }
        
        return ans;
    }
};
