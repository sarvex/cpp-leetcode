/**
 * @brief BFS simulation of domino falling with force collision handling
 * @intuition Dominoes fall in waves; colliding forces from opposite directions cancel
 * @approach Use BFS starting from initial L/R dominoes. Track time each domino falls
 *           and forces acting on it. If one force acts, domino falls that way; if two
 *           forces at same time, they cancel.
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static auto pushDominoes(const std::string& dominoes) -> std::string {
        const int n = static_cast<int>(dominoes.size());
        std::queue<int> q;
        std::vector<int> time(n, -1);
        std::vector<std::string> force(n);
        
        for (int i = 0; i < n; ++i) {
            if (dominoes[i] == '.') continue;
            q.push(i);
            time[i] = 0;
            force[i].push_back(dominoes[i]);
        }
        
        std::string ans(n, '.');
        while (!q.empty()) {
            const int i = q.front();
            q.pop();
            
            if (force[i].size() == 1) {
                const char f = force[i][0];
                ans[i] = f;
                const int j = (f == 'L') ? (i - 1) : (i + 1);
                
                if (j >= 0 && j < n) {
                    const int t = time[i];
                    if (time[j] == -1) {
                        q.push(j);
                        time[j] = t + 1;
                        force[j].push_back(f);
                    } else if (time[j] == t + 1) {
                        force[j].push_back(f);
                    }
                }
            }
        }
        return ans;
    }
};
