/**
 * @brief Max heap simulation of stone smashing
 * @intuition Always smash two heaviest stones; use max heap for efficiency
 * @approach Pop two largest, push difference if non-zero, return final stone
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int lastStoneWeight(const vector<int>& stones) {
        priority_queue<int> pq;
        for (const int x : stones) {
            pq.push(x);
        }
        while (pq.size() > 1) {
            const int y = pq.top();
            pq.pop();
            const int x = pq.top();
            pq.pop();
            if (x != y) {
                pq.push(y - x);
            }
        }
        return pq.empty() ? 0 : pq.top();
    }
};
