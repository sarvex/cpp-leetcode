/**
 * @brief Pick random point uniformly from non-overlapping rectangles
 * @intuition Weight rectangles by area, pick rectangle then point in it
 * @approach Prefix sum of areas, binary search to pick rectangle
 * @complexity Time: O(n) constructor, O(log n) pick, Space: O(n)
 */
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <vector>

class Solution final {
public:
    explicit Solution(const std::vector<std::vector<int>>& rects) : rects_(rects) {
        const int n = static_cast<int>(rects.size());
        prefixSum_.resize(n + 1, 0);

        for (int i = 0; i < n; ++i) {
            const int width = rects[i][2] - rects[i][0] + 1;
            const int height = rects[i][3] - rects[i][1] + 1;
            prefixSum_[i + 1] = prefixSum_[i] + width * height;
        }

        std::srand(static_cast<unsigned>(std::time(nullptr)));
    }

    [[nodiscard]] auto pick() const -> std::vector<int> {
        const int n = static_cast<int>(rects_.size());
        const int target = 1 + std::rand() % prefixSum_[n];
        const int idx = static_cast<int>(
            std::lower_bound(prefixSum_.begin(), prefixSum_.end(), target) - prefixSum_.begin()) - 1;

        const auto& rect = rects_[idx];
        const int x = rect[0] + std::rand() % (rect[2] - rect[0] + 1);
        const int y = rect[1] + std::rand() % (rect[3] - rect[1] + 1);

        return {x, y};
    }

private:
    std::vector<std::vector<int>> rects_;
    std::vector<int> prefixSum_;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
