/**
 * @brief Union-Find to count maximum removable stones
 * @intuition Stones in same row/column form connected components
 * @approach Union stones sharing row or column; removals = stones - components
 * @complexity Time: O(n^2 * α(n)), Space: O(n)
 */
class UnionFind {
public:
    explicit UnionFind(const int n) : p(n), size(n, 1) {
        iota(p.begin(), p.end(), 0);
    }

    bool unite(const int a, const int b) {
        int pa = find(a), pb = find(b);
        if (pa == pb) {
            return false;
        }
        if (size[pa] > size[pb]) {
            p[pb] = pa;
            size[pa] += size[pb];
        } else {
            p[pa] = pb;
            size[pb] += size[pa];
        }
        return true;
    }

    int find(const int x) {
        if (p[x] != x) {
            p[x] = find(p[x]);
        }
        return p[x];
    }

private:
    vector<int> p, size;
};

class Solution final {
public:
    [[nodiscard]] static int removeStones(const vector<vector<int>>& stones) {
        const int n = static_cast<int>(stones.size());
        UnionFind uf(n);
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
                    ans += uf.unite(i, j);
                }
            }
        }
        return ans;
    }
};
