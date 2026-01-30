/**
 * @brief Binary search for minimum eating speed to finish in h hours
 * @intuition Answer is monotonic: if speed k works, k+1 also works
 * @approach Binary search on speed. For each speed, calculate total hours needed.
 *           Find minimum speed where hours <= h.
 * @complexity Time: O(n log m) where m is max pile size, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto minEatingSpeed(const std::vector<int>& piles,
                                              int h) -> int {
        int l = 1, r = std::ranges::max(piles);
        
        while (l < r) {
            const int mid = (l + r) >> 1;
            int hours = 0;
            for (const int x : piles) {
                hours += (x + mid - 1) / mid;
            }
            if (hours <= h) {
                r = mid;
            } else {
                l = mid + 1;
            }
        }
        return l;
    }
};
