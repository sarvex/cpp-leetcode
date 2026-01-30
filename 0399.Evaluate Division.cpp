/**
 * @brief Evaluate division queries given variable equations
 * @intuition Model as weighted graph, use Union-Find with path compression
 * @approach Union-Find where weight represents ratio to root
 * @complexity Time: O(n * alpha(n)) per query, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] auto calcEquation(std::vector<std::vector<std::string>>& equations,
                                     std::vector<double>& values,
                                     std::vector<std::vector<std::string>>& queries)
        -> std::vector<double> {
        std::unordered_map<std::string, std::string> parent;
        std::unordered_map<std::string, double> weight;

        for (const auto& e : equations) {
            parent[e[0]] = e[0];
            parent[e[1]] = e[1];
            weight[e[0]] = 1.0;
            weight[e[1]] = 1.0;
        }

        const auto n = static_cast<int>(equations.size());
        for (int i = 0; i < n; ++i) {
            const auto& a = equations[i][0];
            const auto& b = equations[i][1];
            auto pa = find(a, parent, weight);
            auto pb = find(b, parent, weight);
            if (pa == pb) {
                continue;
            }
            parent[pa] = pb;
            weight[pa] = weight[b] * values[i] / weight[a];
        }

        std::vector<double> ans;
        ans.reserve(queries.size());

        for (const auto& q : queries) {
            const auto& c = q[0];
            const auto& d = q[1];
            if (!parent.contains(c) || !parent.contains(d) || find(c, parent, weight) != find(d, parent, weight)) {
                ans.push_back(-1.0);
            } else {
                ans.push_back(weight[c] / weight[d]);
            }
        }

        return ans;
    }

private:
    static auto find(const std::string& x,
                     std::unordered_map<std::string, std::string>& parent,
                     std::unordered_map<std::string, double>& weight) -> std::string {
        if (parent[x] != x) {
            auto origin = parent[x];
            parent[x] = find(parent[x], parent, weight);
            weight[x] *= weight[origin];
        }
        return parent[x];
    }
};
