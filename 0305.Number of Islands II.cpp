/**
 * @brief Union-Find to count islands after adding land
 * @intuition Track connected components using Union-Find with path compression
 * @approach For each new land, check and union with adjacent lands
 * @complexity Time: O(k * alpha(mn)) where k is number of operations, Space: O(mn)
 */
#include <array>
#include <numeric>
#include <vector>

class UnionFind final {
public:
    explicit UnionFind(int n) : parent_(n), size_(n, 1) {
        std::iota(parent_.begin(), parent_.end(), 0);
    }

    [[nodiscard]] bool unite(int a, int b) {
        const int pa = find(a);
        const int pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size_[pa] > size_[pb]) {
            parent_[pb] = pa;
            size_[pa] += size_[pb];
        } else {
            parent_[pa] = pb;
            size_[pb] += size_[pa];
        }
        return true;
    }

    [[nodiscard]] int find(int x) {
        if (parent_[x] != x) {
            parent_[x] = find(parent_[x]);
        }
        return parent_[x];
    }

private:
    std::vector<int> parent_;
    std::vector<int> size_;
};

class Solution final {
public:
    [[nodiscard]] std::vector<int> numIslands2(int m, int n, 
                                                std::vector<std::vector<int>>& positions) const {
        std::vector<std::vector<int>> grid(m, std::vector<int>(n, 0));
        UnionFind uf(m * n);
        constexpr std::array<int, 5> dirs = {-1, 0, 1, 0, -1};
        int cnt = 0;
        std::vector<int> ans;
        
        for (const auto& pos : positions) {
            const int i = pos[0];
            const int j = pos[1];
            if (grid[i][j] != 0) {
                ans.push_back(cnt);
                continue;
            }
            grid[i][j] = 1;
            ++cnt;
            
            for (int k = 0; k < 4; ++k) {
                const int x = i + dirs[k];
                const int y = j + dirs[k + 1];
                if (x >= 0 && x < m && y >= 0 && y < n && 
                    grid[x][y] != 0 && uf.unite(i * n + j, x * n + y)) {
                    --cnt;
                }
            }
            ans.push_back(cnt);
        }
        return ans;
    }
};
