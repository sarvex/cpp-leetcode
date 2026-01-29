/**
 * @brief Simplify an absolute Unix-style file path
 * @intuition Use a stack to handle directory navigation with ".." and "."
 * @approach Split by '/', push directories, pop on "..", ignore "." and empty
 * @complexity Time: O(n), Space: O(n)
 */

class Solution final {
public:
  [[nodiscard]] static auto simplifyPath(std::string const& path) -> std::string {
    std::deque<std::string> stk;
    std::stringstream ss(path);
    std::string token;

    while (std::getline(ss, token, '/')) {
      if (token.empty() || token == ".") {
        continue;
      }
      if (token == "..") {
        if (!stk.empty()) {
          stk.pop_back();
        }
      } else {
        stk.push_back(token);
      }
    }

    if (stk.empty()) {
      return "/";
    }

    std::string ans;
    for (auto const& s : stk) {
      ans += "/" + s;
    }

    return ans;
  }
};
