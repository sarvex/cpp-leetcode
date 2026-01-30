/**
 * @brief Greedy selection with two priority queues for IPO maximization
 * @intuition Always pick the most profitable project we can afford to maximize capital
 * @approach Use min-heap sorted by capital requirement and max-heap for available profits.
 *           For each round, move all affordable projects to available heap, then pick the best.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto findMaximizedCapital(int k, int w, 
                                                    const vector<int>& profits, 
                                                    const vector<int>& capital) -> int {
        using pii = pair<int, int>;
        priority_queue<pii, vector<pii>, greater<pii>> minHeap;
        const int n = static_cast<int>(profits.size());
        
        for (int i = 0; i < n; ++i) {
            minHeap.emplace(capital[i], profits[i]);
        }
        
        priority_queue<int> maxHeap;
        while (k--) {
            while (!minHeap.empty() && minHeap.top().first <= w) {
                maxHeap.push(minHeap.top().second);
                minHeap.pop();
            }
            if (maxHeap.empty()) break;
            w += maxHeap.top();
            maxHeap.pop();
        }
        return w;
    }
};
