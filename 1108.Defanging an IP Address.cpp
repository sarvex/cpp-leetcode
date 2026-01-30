/**
 * @brief Replace dots with "[.]" in IP address
 * @intuition Simple string replacement traversing from end to avoid index shifting
 * @approach Iterate backwards through the string and replace each '.' with "[.]"
 * @complexity Time: O(n), Space: O(1) in-place modification
 */
class Solution final {
public:
    [[nodiscard]] static string defangIPaddr(string address) {
        for (int i = address.size(); i >= 0; --i) {
            if (address[i] == '.') {
                address.replace(i, 1, "[.]");
            }
        }
        return address;
    }
};
