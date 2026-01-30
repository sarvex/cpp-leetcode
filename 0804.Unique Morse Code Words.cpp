/**
 * @brief Hash set for counting unique Morse code transformations
 * @intuition Convert each word to its Morse code representation and count unique ones
 * @approach Map each character to its Morse code using lookup table, concatenate for
 *           each word, and use a set to track unique transformations.
 * @complexity Time: O(n * k) where k is average word length, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto uniqueMorseRepresentations(
        const std::vector<std::string>& words) -> int {
        constexpr std::array<std::string_view, 26> codes = {
            ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..",
            ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.",
            "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."
        };
        
        std::unordered_set<std::string> s;
        for (const auto& word : words) {
            std::string t;
            for (const char c : word) {
                t += codes[c - 'a'];
            }
            s.insert(std::move(t));
        }
        return static_cast<int>(s.size());
    }
};
