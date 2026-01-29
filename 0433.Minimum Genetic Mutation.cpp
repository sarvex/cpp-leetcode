/**
 * @brief Find minimum mutations to transform start gene to end gene
 * @intuition Each mutation changes one character, BFS finds shortest path
 * @approach BFS through valid gene bank, count steps to reach target
 * @complexity Time: O(n * 8) Space: O(n)
 */
#include <queue>
#include <string>
#include <unordered_set>
#include <utility>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto minMutation(const std::string& startGene, const std::string& endGene,
                                    std::vector<std::string>& bank) const -> int {
        std::queue<std::pair<std::string, int>> q{{{startGene, 0}}};
        std::unordered_set<std::string> vis = {startGene};

        while (!q.empty()) {
            auto [gene, depth] = q.front();
            q.pop();

            if (gene == endGene) {
                return depth;
            }

            for (const std::string& next : bank) {
                int c = 2;
                for (int k = 0; k < 8 && c > 0; ++k) {
                    c -= (gene[k] != next[k]);
                }
                if (c > 0 && !vis.contains(next)) {
                    vis.insert(next);
                    q.push({next, depth + 1});
                }
            }
        }

        return -1;
    }
};
