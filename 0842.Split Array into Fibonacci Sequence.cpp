/**
 * @brief Backtracking to find valid Fibonacci-like sequence split
 * @intuition First two numbers determine the rest; try all valid first two choices
 * @approach For each starting pair, greedily check if rest follows Fibonacci rule.
 *           Handle leading zeros (only "0" allowed), and INT_MAX overflow.
 * @complexity Time: O(n^2 * n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto splitIntoFibonacci(const std::string& num)
        -> std::vector<int> {
        const int n = static_cast<int>(num.size());
        std::vector<int> ans;
        
        auto dfs = [&](auto&& self, int i) -> bool {
            if (i == n) {
                return ans.size() > 2;
            }
            
            long long x = 0;
            for (int j = i; j < n; ++j) {
                if (j > i && num[i] == '0') break;
                
                x = x * 10 + num[j] - '0';
                if (x > INT_MAX) break;
                
                if (ans.size() > 1) {
                    const long long expected = 
                        static_cast<long long>(ans[ans.size() - 1]) + ans[ans.size() - 2];
                    if (x > expected) break;
                    if (x < expected) continue;
                }
                
                ans.push_back(static_cast<int>(x));
                if (self(self, j + 1)) return true;
                ans.pop_back();
            }
            return false;
        };
        
        dfs(dfs, 0);
        return ans;
    }
};
