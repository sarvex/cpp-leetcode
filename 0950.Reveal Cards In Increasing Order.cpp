/**
 * @brief Arrange deck to reveal cards in increasing order
 * @intuition Reverse simulation: insert largest first, rotate
 * @approach Sort descending; for each card, rotate deque then insert at front
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> deckRevealedIncreasing(vector<int>& deck) {
        ranges::sort(deck, greater<int>());
        deque<int> q;
        for (const int v : deck) {
            if (!q.empty()) {
                q.push_front(q.back());
                q.pop_back();
            }
            q.push_front(v);
        }
        return vector<int>(q.begin(), q.end());
    }
};
