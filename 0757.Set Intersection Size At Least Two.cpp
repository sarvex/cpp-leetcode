/**
 * @brief Minimum set size to intersect each interval at least twice
 * @intuition Greedy: sort by end, pick rightmost elements from each interval
 * @approach Track last two picked elements, extend set when needed
 * @complexity Time: O(n log n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static int intersectionSizeTwo(std::vector<std::vector<int>>& intervals) {
        std::ranges::sort(intervals, [](const auto& a, const auto& b) {
            return a[1] == b[1] ? a[0] > b[0] : a[1] < b[1];
        });
        
        int result = 0;
        int second = -1;
        int first = -1;
        
        for (const auto& interval : intervals) {
            const int start = interval[0];
            const int end = interval[1];
            
            if (start <= second) {
                continue;
            }
            if (start > first) {
                result += 2;
                second = end - 1;
                first = end;
            } else {
                ++result;
                second = first;
                first = end;
            }
        }
        return result;
    }
};
