/**
 * @brief Memoized recursion for soup serving probability
 * @intuition Probability converges to 1 for large n; use DP for small values
 * @approach Use memoization with scaled-down serving sizes (divide by 25).
 *           For n > 4800, probability is essentially 1. Otherwise compute
 *           recursively with 4 equally likely serving options.
 * @complexity Time: O((n/25)^2), Space: O((n/25)^2)
 */
class Solution final {
public:
    [[nodiscard]] static auto soupServings(int n) -> double {
        if (n > 4800) return 1.0;
        
        std::array<std::array<double, 200>, 200> f{};
        
        auto dfs = [&](auto&& self, int i, int j) -> double {
            if (i <= 0 && j <= 0) return 0.5;
            if (i <= 0) return 1.0;
            if (j <= 0) return 0.0;
            if (f[i][j] > 0) return f[i][j];
            
            const double ans = 0.25 * (self(self, i - 4, j) + 
                                        self(self, i - 3, j - 1) +
                                        self(self, i - 2, j - 2) + 
                                        self(self, i - 1, j - 3));
            f[i][j] = ans;
            return ans;
        };
        
        const int scaled = (n + 24) / 25;
        return dfs(dfs, scaled, scaled);
    }
};
