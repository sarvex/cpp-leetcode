/**
 * @brief Monotonic stack to find contribution of each element as minimum
 * @intuition Each element contributes to subarrays where it's the minimum
 * @approach Use two passes to find previous/next smaller elements; multiply ranges
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int sumSubarrayMins(const vector<int>& arr) {
        const int n = static_cast<int>(arr.size());
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> stk;
        for (int i = 0; i < n; ++i) {
            while (!stk.empty() && arr[stk.top()] >= arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                left[i] = stk.top();
            }
            stk.push(i);
        }
        stk = stack<int>();
        for (int i = n - 1; i >= 0; --i) {
            while (!stk.empty() && arr[stk.top()] > arr[i]) {
                stk.pop();
            }
            if (!stk.empty()) {
                right[i] = stk.top();
            }
            stk.push(i);
        }
        constexpr int mod = 1e9 + 7;
        long long ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += 1LL * (i - left[i]) * (right[i] - i) * arr[i] % mod;
            ans %= mod;
        }
        return static_cast<int>(ans);
    }
};
