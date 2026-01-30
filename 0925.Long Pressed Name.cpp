/**
 * @brief Verify if typed string could result from long-pressing name
 * @intuition Each character group in typed must be >= corresponding in name
 * @approach Compare character runs; typed run length must be >= name run length
 * @complexity Time: O(n + m), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static bool isLongPressedName(const string& name, const string& typed) {
        const int m = static_cast<int>(name.length()), n = static_cast<int>(typed.length());
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (name[i] != typed[j]) {
                return false;
            }
            int x = i + 1;
            while (x < m && name[x] == name[i]) {
                ++x;
            }
            int y = j + 1;
            while (y < n && typed[y] == typed[j]) {
                ++y;
            }
            if (x - i > y - j) {
                return false;
            }
            i = x;
            j = y;
        }
        return i == m && j == n;
    }
};
