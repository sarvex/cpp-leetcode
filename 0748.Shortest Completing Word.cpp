/**
 * @brief Find shortest word containing all license plate letters
 * @intuition Count letters in plate, find shortest word with sufficient counts
 * @approach Count letters, check each word has at least required character counts
 * @complexity Time: O(n*L) where L is word length, Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static std::string shortestCompletingWord(
            const std::string& licensePlate, 
            const std::vector<std::string>& words) {
        std::array<int, 26> required{};
        for (const char c : licensePlate) {
            if (std::isalpha(c)) {
                ++required[std::tolower(c) - 'a'];
            }
        }
        
        std::string result;
        for (const auto& word : words) {
            if (!result.empty() && result.size() <= word.size()) {
                continue;
            }
            
            std::array<int, 26> counts{};
            for (const char c : word) {
                ++counts[c - 'a'];
            }
            
            bool valid = true;
            for (int i = 0; i < 26; ++i) {
                if (required[i] > counts[i]) {
                    valid = false;
                    break;
                }
            }
            
            if (valid) {
                result = word;
            }
        }
        return result;
    }
};
