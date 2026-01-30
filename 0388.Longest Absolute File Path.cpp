/**
 * @brief Find length of longest absolute file path in file system string
 * @intuition Track directory lengths at each depth level using stack
 * @approach Parse by tabs for depth, accumulate path lengths, track max for files
 * @complexity Time: O(n), Space: O(depth)
 */
class Solution final {
public:
    [[nodiscard]] static auto lengthLongestPath(const std::string& input) -> int {
        const auto n = static_cast<int>(input.size());
        int i = 0;
        int ans = 0;
        std::stack<int> stk;

        while (i < n) {
            int indent = 0;
            while (i < n && input[i] == '\t') {
                ++indent;
                ++i;
            }

            int cur = 0;
            bool isFile = false;
            while (i < n && input[i] != '\n') {
                ++cur;
                if (input[i] == '.') {
                    isFile = true;
                }
                ++i;
            }
            ++i;

            while (!stk.empty() && static_cast<int>(stk.size()) > indent) {
                stk.pop();
            }

            if (!stk.empty()) {
                cur += stk.top() + 1;
            }

            if (!isFile) {
                stk.push(cur);
                continue;
            }

            ans = std::max(ans, cur);
        }

        return ans;
    }
};
