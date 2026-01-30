/**
 * @brief Find seat position maximizing distance to nearest person
 * @intuition Consider gaps between people and edges; optimal is mid-gap or edge
 * @approach Track first and last occupied seats, and maximum gap between any two
 *           occupied seats. Answer is max of: first seat, n-1-last seat, max_gap/2.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto maxDistToClosest(const std::vector<int>& seats) -> int {
        int first = -1, last = -1;
        int d = 0;
        const int n = static_cast<int>(seats.size());
        
        for (int i = 0; i < n; ++i) {
            if (seats[i] == 1) {
                if (last != -1) {
                    d = std::max(d, i - last);
                }
                if (first == -1) {
                    first = i;
                }
                last = i;
            }
        }
        return std::max({d / 2, first, n - last - 1});
    }
};
