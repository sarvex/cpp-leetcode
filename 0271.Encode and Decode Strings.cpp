/**
 * @brief Length-prefixed encoding for string serialization
 * @intuition Prefix each string with its length to enable unambiguous decoding
 * @approach Store 4-byte length before each string content
 * @complexity Time: O(n) where n is total characters, Space: O(1) extra
 */
#include <cstring>
#include <string>
#include <vector>

class Codec final {
public:
  [[nodiscard]] auto encode(const std::vector<std::string>& strs) const -> std::string {
    std::string result;
    for (const auto& s : strs) {
      auto length = static_cast<int>(s.size());
      result.append(reinterpret_cast<const char*>(&length), sizeof(length));
      result.append(s);
    }
    return result;
  }

  [[nodiscard]] auto decode(const std::string& s) const -> std::vector<std::string> {
    std::vector<std::string> result;
    std::size_t i = 0;
    const auto n = s.size();
    
    while (i < n) {
      int length = 0;
      std::memcpy(&length, s.data() + i, sizeof(length));
      i += sizeof(length);
      result.push_back(s.substr(i, length));
      i += length;
    }
    return result;
  }
};
