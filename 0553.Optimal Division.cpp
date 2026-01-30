/**
 * @brief Maximize division by grouping denominator terms
 * @intuition a/(b/c/d/...) = a*c*d*.../b maximizes result by minimizing denominator
 * @approach Put parentheses around all terms after first: a/(b/c/.../z)
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string optimalDivision(const vector<int>& nums) {
        const int n = static_cast<int>(nums.size());
        
        if (n == 1) {
            return to_string(nums[0]);
        }
        if (n == 2) {
            return to_string(nums[0]) + "/" + to_string(nums[1]);
        }
        
        string ans = to_string(nums[0]) + "/(";
        for (int i = 1; i < n - 1; ++i) {
            ans.append(to_string(nums[i]) + "/");
        }
        ans.append(to_string(nums[n - 1]) + ")");
        
        return ans;
    }
};
