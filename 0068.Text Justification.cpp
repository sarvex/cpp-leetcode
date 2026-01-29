/**
 * @brief Justify text to a given width with proper spacing
 * @intuition Pack words into lines, distribute spaces evenly, handle last line specially
 * @approach Greedily pack words, calculate space distribution, left-justify last line
 * @complexity Time: O(n), Space: O(n) where n is total characters
 */

class Solution final {
public:
  [[nodiscard]] static auto fullJustify(std::vector<std::string>& words, int const maxWidth)
      -> std::vector<std::string> {
    std::vector<std::string> ans;
    int const n = static_cast<int>(words.size());

    for (int i = 0; i < n;) {
      std::vector<std::string> line = {words[i]};
      int cnt = static_cast<int>(words[i].size());
      ++i;

      while (i < n && cnt + 1 + static_cast<int>(words[i].size()) <= maxWidth) {
        cnt += 1 + static_cast<int>(words[i].size());
        line.emplace_back(words[i++]);
      }

      if (i == n || line.size() == 1) {
        std::string left = line[0];
        for (std::size_t j = 1; j < line.size(); ++j) {
          left += " " + line[j];
        }
        std::string right(maxWidth - static_cast<int>(left.size()), ' ');
        ans.emplace_back(left + right);
        continue;
      }

      int const spaceWidth = maxWidth - (cnt - static_cast<int>(line.size()) + 1);
      int const w = spaceWidth / (static_cast<int>(line.size()) - 1);
      int const m = spaceWidth % (static_cast<int>(line.size()) - 1);
      std::string row;

      for (std::size_t j = 0; j < line.size() - 1; ++j) {
        row += line[j] + std::string(w + (static_cast<int>(j) < m ? 1 : 0), ' ');
      }
      row += line.back();
      ans.emplace_back(row);
    }

    return ans;
  }
};
