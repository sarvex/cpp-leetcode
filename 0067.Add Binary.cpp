/**
 * @brief Add two binary strings and return the sum as binary string
 * @intuition Process from least significant bit, track carry
 * @approach Iterate both strings from end, sum bits with carry, reverse result
 * @complexity Time: O(max(m, n)), Space: O(max(m, n))
 */

class Solution final {
public:
  [[nodiscard]] static auto addBinary(std::string const& a, std::string const& b)
      -> std::string {
    std::string ans;
    int i = static_cast<int>(a.size()) - 1;
    int j = static_cast<int>(b.size()) - 1;

    for (int carry = 0; i >= 0 || j >= 0 || carry != 0; --i, --j) {
      carry += (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0);
      ans.push_back((carry % 2) + '0');
      carry /= 2;
    }

    std::ranges::reverse(ans);
    return ans;
  }
};
