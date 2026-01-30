/**
 * @brief Sum importance of employee and all subordinates recursively
 * @intuition DFS from target employee, sum importance values
 * @approach Build id-to-employee map, DFS summing importance of subtree
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int getImportance(const vector<Employee*>& employees, const int id) {
        unordered_map<int, Employee*> d;
        for (auto* e : employees) {
            d[e->id] = e;
        }
        
        auto dfs = [&](this auto&& dfs, int i) -> int {
            int s = d[i]->importance;
            for (const int j : d[i]->subordinates) {
                s += dfs(j);
            }
            return s;
        };
        
        return dfs(id);
    }
};
