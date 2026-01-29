/**
 * @brief Find first occurrence of needle in haystack using KMP algorithm
 * @intuition Use failure function to avoid redundant comparisons
 * @approach Build failure array, then search with backtracking on mismatch
 * @complexity Time: O(m + n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto strStr(const std::string& haystack,
                                   const std::string& needle) -> int {
    if (needle.empty()) {
      return 0;
    }

    const auto failure = buildFailure(needle);
    const int hLen = static_cast<int>(haystack.length());
    const int nLen = static_cast<int>(needle.length());

    for (int i = 0; i <= hLen - nLen; ++i) {
      int j = 0;
      int k = i;

      while (j < nLen && k < hLen) {
        if (haystack[k] != needle[j]) {
          if (failure[j] >= 0) {
            j = failure[j];
            continue;
          }
          break;
        }
        ++k;
        ++j;
      }

      if (j >= nLen) {
        return k - j;
      }
    }

    return -1;
  }

private:
  [[nodiscard]] static auto buildFailure(const std::string& pattern)
      -> std::vector<int> {
    const int len = static_cast<int>(pattern.length());
    std::vector<int> failure(len);
    failure[0] = -1;
    int pre = -1;

    for (int i = 0; i < len - 1;) {
      while (pre >= 0 && pattern[i] != pattern[pre]) {
        pre = failure[pre];
      }
      ++i;
      ++pre;
      failure[i] = (pattern[i] == pattern[pre]) ? failure[pre] : pre;
    }

    return failure;
  }
};
