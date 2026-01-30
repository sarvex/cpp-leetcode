/**
 * @brief Monotonic deque with prefix sums for shortest subarray
 * @intuition Maintain deque of indices with increasing prefix sums
 * @approach Compute prefix sums. Use monotonic deque: pop front while sum >= k
 *           (found valid subarray), pop back if current prefix is smaller
 *           (optimization for future searches).
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto shortestSubarray(const std::vector<int>& nums,
                                                int k) -> int {
        const int n = static_cast<int>(nums.size());
        std::vector<long long> s(n + 1);
        
        for (int i = 0; i < n; ++i) {
            s[i + 1] = s[i] + nums[i];
        }
        
        std::deque<int> q;
        int ans = n + 1;
        
        for (int i = 0; i <= n; ++i) {
            while (!q.empty() && s[i] - s[q.front()] >= k) {
                ans = std::min(ans, i - q.front());
                q.pop_front();
            }
            while (!q.empty() && s[q.back()] >= s[i]) {
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return ans > n ? -1 : ans;
    }
};
