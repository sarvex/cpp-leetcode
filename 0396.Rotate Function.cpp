/**
 * @brief Find maximum value of rotation function F(k) = sum(i * nums[(i+k)%n])
 * @intuition F(k+1) - F(k) = sum(nums) - n * nums[n-k-1]
 * @approach Compute F(0) and sum, derive subsequent F values in O(1)
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto maxRotateFunction(const std::vector<int>& nums) -> int {
        const auto n = static_cast<int>(nums.size());
        int f = 0;
        int s = 0;

        for (int i = 0; i < n; ++i) {
            f += i * nums[i];
            s += nums[i];
        }

        int ans = f;
        for (int i = 1; i < n; ++i) {
            f = f + s - n * nums[n - i];
            ans = std::max(ans, f);
        }

        return ans;
    }
};
