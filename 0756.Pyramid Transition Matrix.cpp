/**
 * @brief Check if pyramid can be built with given transitions
 * @intuition DFS with memoization to try all valid transitions layer by layer
 * @approach Encode allowed transitions as bitmask, recursively build each layer
 * @complexity Time: O(7^n) where n is bottom length, Space: O(n * 7^n)
 */
class Solution final {
public:
    [[nodiscard]] bool pyramidTransition(const std::string& bottom, 
                                         const std::vector<std::string>& allowed) {
        std::memset(transitions_, 0, sizeof(transitions_));
        for (const auto& s : allowed) {
            const int a = s[0] - 'A';
            const int b = s[1] - 'A';
            transitions_[a][b] |= 1 << (s[2] - 'A');
        }
        return dfs(bottom, "");
    }

private:
    int transitions_[7][7]{};
    std::unordered_map<std::string, bool> memo_;

    [[nodiscard]] bool dfs(const std::string& current, const std::string& next) {
        if (current.size() == 1) {
            return true;
        }
        if (next.size() + 1 == current.size()) {
            return dfs(next, "");
        }
        
        const std::string key = current + "." + next;
        if (memo_.contains(key)) {
            return memo_[key];
        }
        
        const int a = current[next.size()] - 'A';
        const int b = current[next.size() + 1] - 'A';
        const int candidates = transitions_[a][b];
        
        for (int i = 0; i < 7; ++i) {
            if ((candidates >> i) & 1) {
                if (dfs(current, next + static_cast<char>(i + 'A'))) {
                    memo_[key] = true;
                    return true;
                }
            }
        }
        memo_[key] = false;
        return false;
    }
};
