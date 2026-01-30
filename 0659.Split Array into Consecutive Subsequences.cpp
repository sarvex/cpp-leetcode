/**
 * @brief Check if array can be split into consecutive subsequences of length >= 3
 * @intuition Track subsequences ending at each value using priority queues by length
 * @approach Greedily extend shortest subsequence or start new one
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static bool isPossible(const vector<int>& nums) {
        unordered_map<int, priority_queue<int, vector<int>, greater<int>>> d;
        
        for (const int v : nums) {
            if (d.count(v - 1)) {
                auto& q = d[v - 1];
                d[v].push(q.top() + 1);
                q.pop();
                if (q.empty()) {
                    d.erase(v - 1);
                }
            } else {
                d[v].push(1);
            }
        }
        
        for (auto& [_, v] : d) {
            if (v.top() < 3) {
                return false;
            }
        }
        return true;
    }
};
