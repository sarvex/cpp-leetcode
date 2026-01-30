/**
 * @brief Greedy selection with priority queue for minimum wage cost
 * @intuition Sort by wage/quality ratio; use heap to track k smallest qualities
 * @approach Sort workers by ratio (wage/quality). Process in order, maintaining
 *           k workers with smallest total quality. Cost = ratio * total_quality.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto mincostToHireWorkers(
        const std::vector<int>& quality,
        const std::vector<int>& wage, int k) -> double {
        const int n = static_cast<int>(quality.size());
        std::vector<std::pair<double, int>> workers(n);
        
        for (int i = 0; i < n; ++i) {
            workers[i] = {static_cast<double>(wage[i]) / quality[i], quality[i]};
        }
        std::ranges::sort(workers);
        
        std::priority_queue<int> pq;
        double ans = 1e18;
        int tot = 0;
        
        for (const auto& [ratio, q] : workers) {
            tot += q;
            pq.push(q);
            if (static_cast<int>(pq.size()) == k) {
                ans = std::min(ans, tot * ratio);
                tot -= pq.top();
                pq.pop();
            }
        }
        return ans;
    }
};
