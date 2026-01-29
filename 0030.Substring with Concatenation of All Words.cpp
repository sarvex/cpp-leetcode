/**
 * @brief Find starting indices of concatenation of all words
 * @intuition Use sliding window with word frequency counting
 * @approach Try each starting offset, slide window by word length
 * @complexity Time: O(n * k), Space: O(m * k) where k is word length
 */

class Solution final {
public:
  [[nodiscard]] static auto findSubstring(const std::string& s,
                                          const std::vector<std::string>& words)
      -> std::vector<int> {
    std::unordered_map<std::string, int> wordCount;
    for (const auto& w : words) {
      ++wordCount[w];
    }

    std::vector<int> result;
    const int sLen = static_cast<int>(s.length());
    const int numWords = static_cast<int>(words.size());
    const int wordLen = static_cast<int>(words[0].length());

    for (int i = 0; i < wordLen; ++i) {
      int left = i;
      int right = i;
      std::unordered_map<std::string, int> windowCount;

      while (right + wordLen <= sLen) {
        std::string word = s.substr(right, wordLen);
        right += wordLen;

        if (wordCount.find(word) == wordCount.end()) {
          windowCount.clear();
          left = right;
          continue;
        }

        ++windowCount[word];

        while (windowCount[word] > wordCount[word]) {
          std::string leftWord = s.substr(left, wordLen);
          if (--windowCount[leftWord] == 0) {
            windowCount.erase(leftWord);
          }
          left += wordLen;
        }

        if (right - left == numWords * wordLen) {
          result.push_back(left);
        }
      }
    }

    return result;
  }
};
