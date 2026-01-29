/**
 * @brief Rearrange string so same characters are k apart
 * @intuition Use max-heap to always pick most frequent available character
 * @approach Priority queue with cooldown queue for k-distance constraint
 * @complexity Time: O(n log 26), Space: O(26)
 */
#include <queue>
#include <string>
#include <unordered_map>
#include <utility>

class Solution final {
public:
    [[nodiscard]] std::string rearrangeString(const std::string& s, int k) const {
        std::unordered_map<char, int> cnt;
        for (const char c : s) {
            ++cnt[c];
        }
        
        std::priority_queue<std::pair<int, char>> pq;
        for (const auto& [c, freq] : cnt) {
            pq.emplace(freq, c);
        }
        
        std::queue<std::pair<int, char>> cooldown;
        std::string ans;
        
        while (!pq.empty()) {
            auto [freq, c] = pq.top();
            pq.pop();
            ans += c;
            cooldown.emplace(freq - 1, c);
            
            if (static_cast<int>(cooldown.size()) >= k) {
                auto [f, ch] = cooldown.front();
                cooldown.pop();
                if (f > 0) {
                    pq.emplace(f, ch);
                }
            }
        }
        
        return ans.size() == s.size() ? ans : "";
    }
};
