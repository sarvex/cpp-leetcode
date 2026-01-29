/**
 * @brief Count how many times sentence fits on screen with given rows and cols
 * @intuition Concatenate sentence with spaces, track cursor position in string
 * @approach Advance cursor by cols each row, adjust if landing mid-word
 * @complexity Time: O(rows) Space: O(sentence length)
 */
#include <string>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto wordsTyping(std::vector<std::string>& sentence, int rows, int cols) const -> int {
        std::string s;
        for (const auto& t : sentence) {
            s += t;
            s += " ";
        }

        const int m = static_cast<int>(s.size());
        int cur = 0;

        while (rows-- > 0) {
            cur += cols;
            if (s[cur % m] == ' ') {
                ++cur;
            } else {
                while (cur > 0 && s[(cur - 1) % m] != ' ') {
                    --cur;
                }
            }
        }

        return cur / m;
    }
};
