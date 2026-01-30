/**
 * @brief Count strobogrammatic numbers in range
 * @intuition Generate all strobogrammatic numbers of valid lengths and count in range
 * @approach Generate numbers for each length, filter by range bounds
 * @complexity Time: O(5^(n/2) * m) where m is max digit count, Space: O(5^(n/2))
 */

class Solution final {
public:
  [[nodiscard]] auto strobogrammaticInRange(const std::string& low, const std::string& high) const -> int {
    const std::vector<std::pair<char, char>> pairs = {{'1', '1'}, {'8', '8'}, {'6', '9'}, {'9', '6'}};
    int targetLen = 0;
    
    std::function<std::vector<std::string>(int)> generate = [&](const int len) -> std::vector<std::string> {
      if (len == 0) {
        return {""};
      }
      if (len == 1) {
        return {"0", "1", "8"};
      }
      
      std::vector<std::string> result;
      for (const auto& inner : generate(len - 2)) {
        for (const auto& [left, right] : pairs) {
          result.push_back(left + inner + right);
        }
        if (len != targetLen) {
          result.push_back('0' + inner + '0');
        }
      }
      return result;
    };
    
    const auto lowLen = static_cast<int>(low.size());
    const auto highLen = static_cast<int>(high.size());
    const auto lowVal = std::stoll(low);
    const auto highVal = std::stoll(high);
    
    int count = 0;
    for (targetLen = lowLen; targetLen <= highLen; ++targetLen) {
      for (const auto& s : generate(targetLen)) {
        const auto val = std::stoll(s);
        if (lowVal <= val && val <= highVal) {
          ++count;
        }
      }
    }
    return count;
  }
};
