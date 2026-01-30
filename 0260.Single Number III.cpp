/**
 * @brief XOR and bit manipulation for two single numbers
 * @intuition XOR all gives a^b, isolate distinguishing bit to separate groups
 * @approach Find lowest set bit in XOR result to partition numbers
 * @complexity Time: O(n), Space: O(1)
 */
class Solution final {
public:
  [[nodiscard]] static auto singleNumber(const std::vector<int>& nums) -> std::vector<int> {
    long long xorAll = 0;
    for (const int num : nums) {
      xorAll ^= num;
    }
    
    const auto lowestBit = xorAll & (-xorAll);
    int a = 0;
    for (const int num : nums) {
      if (num & lowestBit) {
        a ^= num;
      }
    }
    const int b = static_cast<int>(xorAll) ^ a;
    return {a, b};
  }
};
