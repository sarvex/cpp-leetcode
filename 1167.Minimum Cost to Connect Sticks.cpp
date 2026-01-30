/**
 * @brief Huffman-like greedy algorithm to minimize stick connection cost
 * @intuition Always connect two shortest sticks to minimize accumulated cost
 * @approach Use min-heap to always extract two smallest sticks. Connect them (sum is the cost),
 *           add combined stick back to heap. Repeat until one stick remains.
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int connectSticks(const vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int x : sticks) {
            pq.push(x);
        }
        int ans = 0;
        while (pq.size() > 1) {
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            int z = x + y;
            ans += z;
            pq.push(z);
        }
        return ans;
    }
};
