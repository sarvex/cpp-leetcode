/**
 * @brief Find path on alphabet board from start to each target character
 * @intuition Board is 5x5 with 'z' at position (5,0). Move left/up before right/down to avoid going off board.
 * @approach Convert each character to (row, col). Move in order: left, up, right, down to handle 'z' corner case.
 * @complexity Time: O(n * max_distance), Space: O(n) for result
 */
class Solution final {
public:
    [[nodiscard]] static string alphabetBoardPath(const string& target) {
        string ans;
        int i = 0, j = 0;
        for (char c : target) {
            int v = c - 'a';
            int x = v / 5, y = v % 5;
            while (j > y) {
                --j;
                ans += 'L';
            }
            while (i > x) {
                --i;
                ans += 'U';
            }
            while (j < y) {
                ++j;
                ans += 'R';
            }
            while (i < x) {
                ++i;
                ans += 'D';
            }
            ans += '!';
        }
        return ans;
    }
};
