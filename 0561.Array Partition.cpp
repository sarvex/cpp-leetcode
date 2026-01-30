/**
 * @brief Maximize sum of pair minimums by sorting
 * @intuition Pairing smallest with next smallest wastes least value in min operation
 * @approach Sort array, sum elements at even indices (the minimums of each pair)
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        
        int ans = 0;
        for (size_t i = 0; i < nums.size(); i += 2) {
            ans += nums[i];
        }
        
        return ans;
    }
};
