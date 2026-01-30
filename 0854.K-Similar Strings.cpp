/**
 * @brief BFS to find minimum swaps transforming s1 to s2
 * @intuition Each state is a string; BFS explores all valid single swaps
 * @approach Use BFS starting from s1. At each step, find first mismatch and try
 *           swapping with later characters that fix the mismatch. Track visited states.
 * @complexity Time: O(n! * n), Space: O(n!)
 */
class Solution final {
    [[nodiscard]] static auto getNextStates(std::string s,
                                             const std::string& target)
        -> std::vector<std::string> {
        const int n = static_cast<int>(s.size());
        int i = 0;
        while (s[i] == target[i]) ++i;
        
        std::vector<std::string> res;
        for (int j = i + 1; j < n; ++j) {
            if (s[j] == target[i] && s[j] != target[j]) {
                std::swap(s[i], s[j]);
                res.push_back(s);
                std::swap(s[i], s[j]);
            }
        }
        return res;
    }

public:
    [[nodiscard]] static auto kSimilarity(const std::string& s1,
                                           const std::string& s2) -> int {
        std::queue<std::string> q{{s1}};
        std::unordered_set<std::string> vis{{s1}};
        int ans = 0;
        
        while (true) {
            for (int k = static_cast<int>(q.size()); k > 0; --k) {
                auto s = q.front();
                q.pop();
                
                if (s == s2) return ans;
                
                for (auto& nxt : getNextStates(s, s2)) {
                    if (!vis.contains(nxt)) {
                        vis.insert(nxt);
                        q.push(nxt);
                    }
                }
            }
            ++ans;
        }
    }
};
