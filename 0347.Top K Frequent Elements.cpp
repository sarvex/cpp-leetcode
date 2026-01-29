/**
 * @brief Find k most frequent elements using min-heap
 * @intuition Use hash map for frequency, min-heap to maintain top k
 * @approach Count frequencies, use min-heap of size k for most frequent
 * @complexity Time: O(n log k), Space: O(n + k)
 */
#include <functional>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] std::vector<int> topKFrequent(const std::vector<int>& nums, int k) const {
        std::unordered_map<int, int> cnt;
        for (const int x : nums) {
            ++cnt[x];
        }
        
        using pii = std::pair<int, int>;
        std::priority_queue<pii, std::vector<pii>, std::greater<>> pq;
        
        for (const auto& [num, freq] : cnt) {
            pq.emplace(freq, num);
            if (static_cast<int>(pq.size()) > k) {
                pq.pop();
            }
        }
        
        std::vector<int> ans;
        ans.reserve(k);
        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
