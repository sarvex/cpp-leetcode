/**
 * @brief Merge accounts using Union-Find
 * @intuition Emails belonging to same person form connected components
 * @approach Union-Find to group accounts sharing emails, collect emails by root
 * @complexity Time: O(n*k*α(n)), Space: O(n*k) where k is avg emails per account
 */
class Solution final {
    class UnionFind {
    public:
        explicit UnionFind(const int n) : parent_(n), rank_(n, 1) {
            std::iota(parent_.begin(), parent_.end(), 0);
        }

        void unite(int a, int b) {
            const int pa = find(a);
            const int pb = find(b);
            if (pa == pb) return;
            if (rank_[pa] > rank_[pb]) {
                parent_[pb] = pa;
                rank_[pa] += rank_[pb];
            } else {
                parent_[pa] = pb;
                rank_[pb] += rank_[pa];
            }
        }

        [[nodiscard]] int find(int x) {
            if (parent_[x] != x) {
                parent_[x] = find(parent_[x]);
            }
            return parent_[x];
        }

    private:
        std::vector<int> parent_;
        std::vector<int> rank_;
    };

public:
    [[nodiscard]] static std::vector<std::vector<std::string>> accountsMerge(
            std::vector<std::vector<std::string>>& accounts) {
        const int n = static_cast<int>(accounts.size());
        UnionFind uf(n);
        std::unordered_map<std::string, int> emailToId;
        
        for (int i = 0; i < n; ++i) {
            for (size_t j = 1; j < accounts[i].size(); ++j) {
                const auto& email = accounts[i][j];
                if (emailToId.contains(email)) {
                    uf.unite(i, emailToId[email]);
                } else {
                    emailToId[email] = i;
                }
            }
        }
        
        std::unordered_map<int, std::set<std::string>> groupedEmails;
        for (int i = 0; i < n; ++i) {
            const int root = uf.find(i);
            groupedEmails[root].insert(accounts[i].begin() + 1, accounts[i].end());
        }
        
        std::vector<std::vector<std::string>> result;
        for (const auto& [root, emails] : groupedEmails) {
            std::vector<std::string> merged(emails.begin(), emails.end());
            merged.insert(merged.begin(), accounts[root][0]);
            result.push_back(std::move(merged));
        }
        return result;
    }
};
