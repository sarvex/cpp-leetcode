/**
 * @brief Find shortest subarray with same degree as full array
 * @intuition Track count, first and last occurrence of each element
 * @approach Elements with max frequency determine candidates for shortest range
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int findShortestSubArray(const vector<int>& nums) {
        unordered_map<int, int> cnt;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        int degree = 0;
        
        for (size_t i = 0; i < nums.size(); ++i) {
            const int v = nums[i];
            degree = max(degree, ++cnt[v]);
            if (!left.count(v)) {
                left[v] = i;
            }
            right[v] = i;
        }
        
        int ans = nums.size();
        for (const int v : nums) {
            if (cnt[v] == degree) {
                const int t = right[v] - left[v] + 1;
                ans = min(ans, t);
            }
        }
        return ans;
    }
};
