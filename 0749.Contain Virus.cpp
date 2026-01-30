/**
 * @brief Contain virus by building walls around most threatening region
 * @intuition Each day, quarantine region threatening most cells, spread others
 * @approach DFS to find regions, prioritize by threat level, simulate spread
 * @complexity Time: O((m*n)^2), Space: O(m*n)
 */
class Solution final {
public:
    [[nodiscard]] int containVirus(std::vector<std::vector<int>>& isInfected) {
        infected_ = std::move(isInfected);
        m_ = static_cast<int>(infected_.size());
        n_ = static_cast<int>(infected_[0].size());
        int totalWalls = 0;

        while (true) {
            visited_.assign(m_, std::vector<bool>(n_, false));
            wallCounts_.clear();
            regions_.clear();
            boundaries_.clear();

            for (int i = 0; i < m_; ++i) {
                for (int j = 0; j < n_; ++j) {
                    if (infected_[i][j] == 1 && !visited_[i][j]) {
                        wallCounts_.push_back(0);
                        regions_.emplace_back();
                        boundaries_.emplace_back();
                        dfs(i, j);
                    }
                }
            }

            if (regions_.empty()) break;

            const int idx = findMostThreatening();
            totalWalls += wallCounts_[idx];

            for (size_t t = 0; t < regions_.size(); ++t) {
                if (static_cast<int>(t) == idx) {
                    for (const int cell : regions_[t]) {
                        infected_[cell / n_][cell % n_] = -1;
                    }
                } else {
                    for (const int cell : regions_[t]) {
                        const int i = cell / n_;
                        const int j = cell % n_;
                        for (int k = 0; k < 4; ++k) {
                            const int x = i + kDirs[k];
                            const int y = j + kDirs[k + 1];
                            if (x >= 0 && x < m_ && y >= 0 && y < n_ && infected_[x][y] == 0) {
                                infected_[x][y] = 1;
                            }
                        }
                    }
                }
            }
        }
        return totalWalls;
    }

private:
    static constexpr std::array<int, 5> kDirs{-1, 0, 1, 0, -1};
    std::vector<std::vector<int>> infected_;
    std::vector<std::vector<bool>> visited_;
    std::vector<int> wallCounts_;
    std::vector<std::vector<int>> regions_;
    std::vector<std::unordered_set<int>> boundaries_;
    int m_, n_;

    void dfs(const int i, const int j) {
        visited_[i][j] = true;
        regions_.back().push_back(i * n_ + j);
        for (int k = 0; k < 4; ++k) {
            const int x = i + kDirs[k];
            const int y = j + kDirs[k + 1];
            if (x >= 0 && x < m_ && y >= 0 && y < n_) {
                if (infected_[x][y] == 1 && !visited_[x][y]) {
                    dfs(x, y);
                } else if (infected_[x][y] == 0) {
                    ++wallCounts_.back();
                    boundaries_.back().insert(x * n_ + y);
                }
            }
        }
    }

    [[nodiscard]] int findMostThreatening() const {
        int idx = 0;
        size_t maxThreat = boundaries_[0].size();
        for (size_t i = 1; i < boundaries_.size(); ++i) {
            if (maxThreat < boundaries_[i].size()) {
                maxThreat = boundaries_[i].size();
                idx = static_cast<int>(i);
            }
        }
        return idx;
    }
};
