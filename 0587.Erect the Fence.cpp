/**
 * @brief Find convex hull of trees using Andrew's monotone chain algorithm
 * @intuition Convex hull is minimum perimeter fence enclosing all trees
 * @approach Sort points, build lower and upper hulls using cross product test
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<int>> outerTrees(vector<vector<int>>& trees) {
        const int n = static_cast<int>(trees.size());
        if (n < 4) {
            return trees;
        }
        
        sort(trees.begin(), trees.end());
        vector<int> visited(n);
        vector<int> stack(n + 10);
        int cnt = 1;
        
        for (int i = 1; i < n; ++i) {
            while (cnt > 1 && cross(trees[stack[cnt - 1]], trees[stack[cnt - 2]], trees[i]) < 0) {
                visited[stack[--cnt]] = false;
            }
            visited[i] = true;
            stack[cnt++] = i;
        }
        
        const int lowerSize = cnt;
        for (int i = n - 1; i >= 0; --i) {
            if (visited[i]) {
                continue;
            }
            while (cnt > lowerSize && cross(trees[stack[cnt - 1]], trees[stack[cnt - 2]], trees[i]) < 0) {
                --cnt;
            }
            stack[cnt++] = i;
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < cnt - 1; ++i) {
            ans.push_back(trees[stack[i]]);
        }
        
        return ans;
    }

private:
    [[nodiscard]] static int cross(const vector<int>& a, const vector<int>& b, const vector<int>& c) {
        return (b[0] - a[0]) * (c[1] - b[1]) - (b[1] - a[1]) * (c[0] - b[0]);
    }
};
