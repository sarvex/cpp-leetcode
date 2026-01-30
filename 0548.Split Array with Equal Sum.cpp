/**
 * @brief Find three indices splitting array into four equal-sum parts
 * @intuition Fix middle index j, use prefix sums to find valid i and k positions
 * @approach For each j, store valid left sums in set, then check if matching right sum exists
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool splitArray(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        vector<int> prefix(n + 1);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        for (int j = 3; j < n - 3; ++j) {
            unordered_set<int> seen;
            
            for (int i = 1; i < j - 1; ++i) {
                if (prefix[i] == prefix[j] - prefix[i + 1]) {
                    seen.insert(prefix[i]);
                }
            }
            
            for (int k = j + 2; k < n - 1; ++k) {
                const int rightSum = prefix[n] - prefix[k + 1];
                if (rightSum == prefix[k] - prefix[j + 1] && seen.contains(rightSum)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};
