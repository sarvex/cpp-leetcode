/**
 * @brief Find duplicate files by content
 * @intuition Group files by their content hash, return groups with more than one file
 * @approach Parse file paths and contents, use hashmap to group by content
 * @complexity Time: O(n * m) where m is average file content length, Space: O(n * m)
 */
class Solution final {
public:
    [[nodiscard]] static vector<vector<string>> findDuplicate(const vector<string>& paths) {
        unordered_map<string, vector<string>> d;
        
        for (const auto& p : paths) {
            auto ps = split(p, ' ');
            for (size_t i = 1; i < ps.size(); ++i) {
                const auto j = ps[i].find('(');
                auto content = ps[i].substr(j + 1, ps[i].size() - j - 2);
                auto name = ps[0] + '/' + ps[i].substr(0, j);
                d[content].push_back(std::move(name));
            }
        }
        
        vector<vector<string>> ans;
        for (auto& [_, e] : d) {
            if (e.size() > 1) {
                ans.push_back(std::move(e));
            }
        }
        return ans;
    }

private:
    [[nodiscard]] static vector<string> split(const string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string t;
        while (getline(ss, t, c)) {
            res.push_back(t);
        }
        return res;
    }
};
