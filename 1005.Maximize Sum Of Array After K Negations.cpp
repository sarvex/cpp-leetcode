/**
 * @brief Greedy negation with frequency counting
 * @intuition Negate smallest negatives first, handle remaining flips on smallest absolute value
 * @approach Count frequencies, flip negatives from smallest, handle odd remaining flips
 * @complexity Time: O(n + C) where C = value range, Space: O(C)
 */
class Solution final {
public:
    [[nodiscard]] static int largestSumAfterKNegations(const std::vector<int>& nums, int k) {
        std::unordered_map<int, int> cnt;
        for (const int x : nums) {
            ++cnt[x];
        }
        for (int x = -100; x < 0 && k > 0; ++x) {
            if (cnt[x]) {
                const int m = std::min(cnt[x], k);
                cnt[x] -= m;
                cnt[-x] += m;
                k -= m;
            }
        }
        if ((k & 1) && !cnt[0]) {
            for (int x = 1; x <= 100; ++x) {
                if (cnt[x]) {
                    --cnt[x];
                    ++cnt[-x];
                    break;
                }
            }
        }
        int ans = 0;
        for (const auto& [x, v] : cnt) {
            ans += x * v;
        }
        return ans;
    }
};
