/**
 * @brief Minimum steps to cut trees in height order
 * @intuition Sort trees by height, find shortest path between consecutive trees
 * @approach A* search for shortest path, process trees in sorted height order
 * @complexity Time: O(m^2 * n^2 * log(mn)), Space: O(mn)
 */
class Solution final {
public:
    [[nodiscard]] int cutOffTree(vector<vector<int>>& forest) {
        m_ = forest.size();
        n_ = forest[0].size();
        dist_.resize(m_ * n_);
        
        vector<pair<int, int>> trees;
        for (int i = 0; i < m_; ++i) {
            for (int j = 0; j < n_; ++j) {
                if (forest[i][j] > 1) {
                    trees.emplace_back(forest[i][j], i * n_ + j);
                }
            }
        }
        ranges::sort(trees);
        
        int ans = 0;
        int start = 0;
        for (const auto& [_, end] : trees) {
            const int t = bfs(start, end, forest);
            if (t == -1) {
                return -1;
            }
            ans += t;
            start = end;
        }
        return ans;
    }

private:
    int m_;
    int n_;
    vector<int> dist_;
    static constexpr int dirs[] = {-1, 0, 1, 0, -1};

    [[nodiscard]] int bfs(const int start, const int end, const vector<vector<int>>& forest) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> q;
        q.push({heuristic(start, end), start});
        ranges::fill(dist_, INT_MAX);
        dist_[start] = 0;
        
        while (!q.empty()) {
            const int state = q.top().second;
            q.pop();
            
            if (state == end) {
                return dist_[state];
            }
            
            for (int k = 0; k < 4; ++k) {
                const int x = state / n_ + dirs[k];
                const int y = state % n_ + dirs[k + 1];
                
                if (x >= 0 && x < m_ && y >= 0 && y < n_ && forest[x][y] && dist_[x * n_ + y] > dist_[state] + 1) {
                    dist_[x * n_ + y] = dist_[state] + 1;
                    q.push({dist_[x * n_ + y] + heuristic(x * n_ + y, end), x * n_ + y});
                }
            }
        }
        return -1;
    }

    [[nodiscard]] int heuristic(const int start, const int end) const {
        return abs(start / n_ - end / n_) + abs(start % n_ - end % n_);
    }
};
