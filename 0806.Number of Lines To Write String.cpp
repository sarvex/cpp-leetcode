/**
 * @brief Linear scan to count lines needed for writing string
 * @intuition Greedily fit as many characters as possible on each line
 * @approach Iterate through characters, adding their widths. When exceeding 100 pixels,
 *           start a new line. Track total lines and width of last line.
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto numberOfLines(const std::vector<int>& widths,
                                             const std::string& s) -> std::vector<int> {
        int lines = 1;
        int last = 0;
        
        for (const char c : s) {
            const int w = widths[c - 'a'];
            if (last + w <= 100) {
                last += w;
            } else {
                ++lines;
                last = w;
            }
        }
        return {lines, last};
    }
};
