/**
 * @brief Check if rectangles form exact cover of rectangular region
 * @intuition Total area must match, and corners must appear correct times
 * @approach Sum areas, count corner occurrences (corners: 1, edges: 2 or 4)
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto isRectangleCover(const std::vector<std::vector<int>>& rectangles) -> bool {
        long long area = 0;
        int minX = rectangles[0][0];
        int minY = rectangles[0][1];
        int maxX = rectangles[0][2];
        int maxY = rectangles[0][3];

        std::map<std::pair<int, int>, int> cnt;

        for (const auto& r : rectangles) {
            area += static_cast<long long>(r[2] - r[0]) * (r[3] - r[1]);

            minX = std::min(minX, r[0]);
            minY = std::min(minY, r[1]);
            maxX = std::max(maxX, r[2]);
            maxY = std::max(maxY, r[3]);

            ++cnt[{r[0], r[1]}];
            ++cnt[{r[0], r[3]}];
            ++cnt[{r[2], r[3]}];
            ++cnt[{r[2], r[1]}];
        }

        if (area != static_cast<long long>(maxX - minX) * (maxY - minY) ||
            cnt[{minX, minY}] != 1 || cnt[{minX, maxY}] != 1 ||
            cnt[{maxX, maxY}] != 1 || cnt[{maxX, minY}] != 1) {
            return false;
        }

        cnt.erase({minX, minY});
        cnt.erase({minX, maxY});
        cnt.erase({maxX, maxY});
        cnt.erase({maxX, minY});

        return std::ranges::all_of(cnt, [](const auto& e) {
            return e.second == 2 || e.second == 4;
        });
    }
};
