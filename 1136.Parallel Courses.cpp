/**
 * @brief Topological sort with BFS to find minimum semesters for all courses
 * @intuition Process courses level by level; each level represents one semester
 * @approach Build dependency graph and compute indegrees. Use BFS starting from courses
 *           with no prerequisites. Count levels until all courses are taken.
 * @complexity Time: O(n + m) where m is number of relations, Space: O(n + m)
 */
class Solution final {
public:
    [[nodiscard]] static int minimumSemesters(int n, const vector<vector<int>>& relations) {
        vector<vector<int>> g(n);
        vector<int> indeg(n);
        for (const auto& r : relations) {
            int prev = r[0] - 1, nxt = r[1] - 1;
            g[prev].push_back(nxt);
            ++indeg[nxt];
        }
        queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }
        int ans = 0;
        while (!q.empty()) {
            ++ans;
            for (int k = q.size(); k; --k) {
                int i = q.front();
                q.pop();
                --n;
                for (int j : g[i]) {
                    if (--indeg[j] == 0) {
                        q.push(j);
                    }
                }
            }
        }
        return n == 0 ? ans : -1;
    }
};
