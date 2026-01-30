/**
 * @brief Minimum swaps for couples to sit together using Union-Find
 * @intuition Each swap can fix at most one misplaced couple; count connected components
 * @approach Union couple indices; swaps needed = n - number of self-loops
 * @complexity Time: O(n*α(n)), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int minSwapsCouples(const std::vector<int>& row) {
        const int n = static_cast<int>(row.size()) / 2;
        std::vector<int> parent(n);
        std::iota(parent.begin(), parent.end(), 0);
        
        auto find = [&](auto&& self, int x) -> int {
            if (parent[x] != x) {
                parent[x] = self(self, parent[x]);
            }
            return parent[x];
        };
        
        for (int i = 0; i < n * 2; i += 2) {
            const int a = row[i] >> 1;
            const int b = row[i + 1] >> 1;
            parent[find(find, a)] = find(find, b);
        }
        
        int swaps = n;
        for (int i = 0; i < n; ++i) {
            swaps -= (i == find(find, i));
        }
        return swaps;
    }
};
