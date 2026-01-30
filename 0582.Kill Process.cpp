/**
 * @brief Find all processes to kill starting from given process
 * @intuition Build parent-to-children graph, then DFS from kill process
 * @approach Create adjacency list from ppid->pid, traverse all descendants
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<int> killProcess(const vector<int>& pid,
                                                  const vector<int>& ppid,
                                                  const int kill) {
        unordered_map<int, vector<int>> children;
        const int n = static_cast<int>(pid.size());
        
        for (int i = 0; i < n; ++i) {
            children[ppid[i]].push_back(pid[i]);
        }
        
        vector<int> ans;
        
        auto dfs = [&](this auto&& dfs, int process) -> void {
            ans.push_back(process);
            for (const int child : children[process]) {
                dfs(child);
            }
        };
        
        dfs(kill);
        return ans;
    }
};
