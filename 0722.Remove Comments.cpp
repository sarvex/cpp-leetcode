/**
 * @brief Remove C-style comments from source code
 * @intuition Track block comment state, handle line and block comments differently
 * @approach Linear scan with state machine for block comments
 * @complexity Time: O(total characters), Space: O(total characters)
 */
class Solution final {
public:
    [[nodiscard]] static std::vector<std::string> removeComments(
            const std::vector<std::string>& source) {
        std::vector<std::string> result;
        std::string currentLine;
        bool inBlockComment = false;
        
        for (const auto& line : source) {
            const int m = static_cast<int>(line.size());
            for (int i = 0; i < m; ++i) {
                if (inBlockComment) {
                    if (i + 1 < m && line[i] == '*' && line[i + 1] == '/') {
                        inBlockComment = false;
                        ++i;
                    }
                } else {
                    if (i + 1 < m && line[i] == '/' && line[i + 1] == '*') {
                        inBlockComment = true;
                        ++i;
                    } else if (i + 1 < m && line[i] == '/' && line[i + 1] == '/') {
                        break;
                    } else {
                        currentLine.push_back(line[i]);
                    }
                }
            }
            if (!inBlockComment && !currentLine.empty()) {
                result.emplace_back(std::move(currentLine));
                currentLine.clear();
            }
        }
        return result;
    }
};
