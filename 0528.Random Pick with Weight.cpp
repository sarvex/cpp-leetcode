/**
 * @brief Random index selection weighted by probability
 * @intuition Build prefix sum array; random number maps to index via binary search
 * @approach Construct prefix sums. For picking, generate random in [1, total],
 *           binary search for first prefix sum >= random value.
 * @complexity Time: O(n) construction, O(log n) per pick, Space: O(n)
 */
class Solution final {
public:
    explicit Solution(const vector<int>& w) : prefixSum(w.size() + 1, 0) {
        for (size_t i = 0; i < w.size(); ++i) {
            prefixSum[i + 1] = prefixSum[i] + w[i];
        }
    }

    [[nodiscard]] auto pickIndex() -> int {
        const int x = 1 + rand() % prefixSum.back();
        const auto it = ranges::lower_bound(prefixSum, x);
        return static_cast<int>(it - prefixSum.begin()) - 1;
    }

private:
    vector<int> prefixSum;
};
