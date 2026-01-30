/**
 * @brief Count how many times sentence fits on screen with given rows and cols
 * @intuition Concatenate sentence with spaces, track cursor position in string
 * @approach Advance cursor by cols each row, adjust if landing mid-word
 * @complexity Time: O(rows), Space: O(sentence length)
 */
class Solution final {
public:
    [[nodiscard]] static auto wordsTyping(const std::vector<std::string>& sentence,
                                           int rows, int cols) -> int {
        std::string s;
        for (const auto& t : sentence) {
            s += t;
            s += " ";
        }

        const auto m = static_cast<int>(s.size());
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
