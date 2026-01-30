/**
 * @brief Generate all letter case permutations
 * @intuition Each letter can be upper or lower; digits stay same
 * @approach DFS: at each letter, branch into both cases
 * @complexity Time: O(2^L * n) where L is letter count, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::string> letterCasePermutation(const std::string& s) {
        std::string current = s;
        std::vector<std::string> result;
        
        auto dfs = [&](auto&& self, const int idx) -> void {
            if (idx >= static_cast<int>(current.size())) {
                result.push_back(current);
                return;
            }
            self(self, idx + 1);
            if (std::isalpha(current[idx])) {
                current[idx] ^= 32;
                self(self, idx + 1);
                current[idx] ^= 32;
            }
        };
        
        dfs(dfs, 0);
        return result;
    }
};
