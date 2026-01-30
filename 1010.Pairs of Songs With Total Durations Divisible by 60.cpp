/**
 * @brief Two-sum variant with modular arithmetic
 * @intuition Pairs sum divisible by 60 means complementary remainders sum to 0 or 60
 * @approach Count remainders, pair complementary values, handle 0 and 30 specially
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int numPairsDivisibleBy60(const vector<int>& time) {
        int cnt[60]{};
        for (const int t : time) {
            ++cnt[t % 60];
        }
        int ans = 0;
        for (int x = 1; x < 30; ++x) {
            ans += cnt[x] * cnt[60 - x];
        }
        ans += 1LL * cnt[0] * (cnt[0] - 1) / 2;
        ans += 1LL * cnt[30] * (cnt[30] - 1) / 2;
        return ans;
    }
};
