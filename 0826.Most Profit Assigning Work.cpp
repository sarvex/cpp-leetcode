/**
 * @brief Greedy job assignment with sorting and two pointers
 * @intuition Sort workers and jobs by difficulty; track max profit seen so far
 * @approach Sort workers ascending. Sort jobs by difficulty. For each worker,
 *           consider all jobs up to their ability, tracking maximum profit.
 * @complexity Time: O(n log n + m log m), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto maxProfitAssignment(const std::vector<int>& difficulty,
                                                   const std::vector<int>& profit,
                                                   std::vector<int>& worker) -> int {
        std::ranges::sort(worker);
        const int n = static_cast<int>(profit.size());
        
        std::vector<std::pair<int, int>> jobs;
        jobs.reserve(n);
        for (int i = 0; i < n; ++i) {
            jobs.emplace_back(difficulty[i], profit[i]);
        }
        std::ranges::sort(jobs);
        
        int ans = 0, mx = 0, i = 0;
        for (const int w : worker) {
            while (i < n && jobs[i].first <= w) {
                mx = std::max(mx, jobs[i++].second);
            }
            ans += mx;
        }
        return ans;
    }
};
