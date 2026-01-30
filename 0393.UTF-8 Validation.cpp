/**
 * @brief Validate if data represents valid UTF-8 encoding
 * @intuition Check leading byte pattern and count continuation bytes
 * @approach State machine: track expected continuation bytes based on lead byte
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static auto validUtf8(const std::vector<int>& data) -> bool {
        int cnt = 0;

        for (const int v : data) {
            if (cnt > 0) {
                if (v >> 6 != 0b10) {
                    return false;
                }
                --cnt;
            } else if (v >> 7 == 0) {
                cnt = 0;
            } else if (v >> 5 == 0b110) {
                cnt = 1;
            } else if (v >> 4 == 0b1110) {
                cnt = 2;
            } else if (v >> 3 == 0b11110) {
                cnt = 3;
            } else {
                return false;
            }
        }

        return cnt == 0;
    }
};
