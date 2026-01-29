/**
 * @brief Find the kth permutation sequence of [1, n]
 * @intuition Use factorial decomposition to determine each digit position
 * @approach Calculate position in each factorial group to pick digits
 * @complexity Time: O(n^2), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto getPermutation(int const n, int k) -> std::string {
    std::string result;
    std::bitset<10> used;

    for (int i = 0; i < n; ++i) {
      int factorial = 1;
      for (int j = 1; j < n - i; ++j) {
        factorial *= j;
      }

      for (int j = 1; j <= n; ++j) {
        if (used[j]) {
          continue;
        }

        if (k > factorial) {
          k -= factorial;
        } else {
          result += std::to_string(j);
          used[j] = true;
          break;
        }
      }
    }

    return result;
  }
};
