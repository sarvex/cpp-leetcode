/**
 * @brief Check if original sequence can be uniquely reconstructed from subsequences
 * @intuition Unique reconstruction means topological sort has single valid order
 * @approach Build graph from sequences, verify single-element queue at each step
 * @complexity Time: O(n + m) where m is total elements in sequences Space: O(n)
 */
#include <queue>
#include <vector>

class Solution final {
public:
    [[nodiscard]] auto sequenceReconstruction(std::vector<int>& nums,
                                               std::vector<std::vector<int>>& sequences) const -> bool {
        const int n = static_cast<int>(nums.size());
        std::vector<int> indeg(n, 0);
        std::vector<std::vector<int>> g(n);

        for (const auto& seq : sequences) {
            for (std::size_t i = 1; i < seq.size(); ++i) {
                const int a = seq[i - 1] - 1;
                const int b = seq[i] - 1;
                g[a].push_back(b);
                ++indeg[b];
            }
        }

        std::queue<int> q;
        for (int i = 0; i < n; ++i) {
            if (indeg[i] == 0) {
                q.push(i);
            }
        }

        while (q.size() == 1) {
            const int i = q.front();
            q.pop();
            for (const int j : g[i]) {
                if (--indeg[j] == 0) {
                    q.push(j);
                }
            }
        }

        return q.empty();
    }
};
