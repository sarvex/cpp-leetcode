/**
 * @brief Find k-th smallest prime fraction using min-heap
 * @intuition Fractions form sorted matrix; use heap to extract k-th smallest
 * @approach Min-heap of (numerator_idx, denominator_idx), expand on pop
 * @complexity Time: O(k log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<int> kthSmallestPrimeFraction(
            const std::vector<int>& arr, const int k) {
        using PII = std::pair<int, int>;
        const int n = static_cast<int>(arr.size());
        
        auto cmp = [&](const PII& a, const PII& b) {
            return arr[a.first] * arr[b.second] > arr[b.first] * arr[a.second];
        };
        
        std::priority_queue<PII, std::vector<PII>, decltype(cmp)> minHeap(cmp);
        for (int i = 1; i < n; ++i) {
            minHeap.push({0, i});
        }
        
        for (int i = 1; i < k; ++i) {
            auto [num, den] = minHeap.top();
            minHeap.pop();
            if (num + 1 < den) {
                minHeap.push({num + 1, den});
            }
        }
        
        return {arr[minHeap.top().first], arr[minHeap.top().second]};
    }
};
