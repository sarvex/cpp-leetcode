#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

class Solution final {
public:
  std::vector<int> findSubstring(std::string s,
                                 std::vector<std::string> &words) {
    std::unordered_map<std::string, int> cnt;
    for (const auto &w : words) {
      cnt[w]++;
    }

    std::vector<int> ans;
    int m = s.length(), n = words.size(), k = words[0].length();

    for (int i = 0; i < k; ++i) {
      int l = i, r = i;
      std::unordered_map<std::string, int> cnt1;
      while (r + k <= m) {
        std::string t = s.substr(r, k);
        r += k;

        if (!cnt.contains(t)) {
          cnt1.clear();
          l = r;
          continue;
        }

        cnt1[t]++;

        while (cnt1[t] > cnt[t]) {
          std::string w = s.substr(l, k);
          if (--cnt1[w] == 0) {
            cnt1.erase(w);
          }
          l += k;
        }

        if (r - l == n * k) {
          ans.push_back(l);
        }
      }
    }

    return ans;
  }
};
