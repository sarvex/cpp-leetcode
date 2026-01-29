/**
 * @brief Count valid Android unlock patterns of length m to n
 * @intuition DFS with pruning based on crossing rules between keys
 * @approach Track crossing requirements, use symmetry (1,3,7,9 same, 2,4,6,8 same)
 * @complexity Time: O(9!), Space: O(9) for recursion
 */
#include <cstring>
#include <functional>

class Solution final {
public:
    [[nodiscard]] int numberOfPatterns(int m, int n) const {
        int cross[10][10];
        std::memset(cross, 0, sizeof(cross));
        bool visited[10];
        std::memset(visited, false, sizeof(visited));
        
        // Set up crossing requirements
        cross[1][3] = cross[3][1] = 2;
        cross[1][7] = cross[7][1] = 4;
        cross[1][9] = cross[9][1] = 5;
        cross[2][8] = cross[8][2] = 5;
        cross[3][7] = cross[7][3] = 5;
        cross[3][9] = cross[9][3] = 6;
        cross[4][6] = cross[6][4] = 5;
        cross[7][9] = cross[9][7] = 8;

        std::function<int(int, int)> dfs = [&](int i, int cnt) -> int {
            if (cnt > n) {
                return 0;
            }
            visited[i] = true;
            int ans = cnt >= m ? 1 : 0;
            
            for (int j = 1; j < 10; ++j) {
                const int required = cross[i][j];
                if (!visited[j] && (required == 0 || visited[required])) {
                    ans += dfs(j, cnt + 1);
                }
            }
            visited[i] = false;
            return ans;
        };

        // Use symmetry: corners (1,3,7,9) are equivalent, edges (2,4,6,8) are equivalent
        return dfs(1, 1) * 4 + dfs(2, 1) * 4 + dfs(5, 1);
    }
};
