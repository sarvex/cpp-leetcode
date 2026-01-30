/**
 * @brief Find most common 3-sequence pattern across user website visits
 * @intuition Group visits by user, generate all 3-sequences, count unique user occurrences
 * @approach For each user, sort visits by time and generate all triplet combinations.
 *           Count each unique triplet per user. Return lexicographically smallest with highest count.
 * @complexity Time: O(n + U * S^3) where U is users, S is max sites per user, Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> mostVisitedPattern(const vector<string>& username,
                                                           const vector<int>& timestamp,
                                                           const vector<string>& website) {
        unordered_map<string, vector<pair<int, string>>> d;
        const int n = username.size();
        for (int i = 0; i < n; ++i) {
            auto user = username[i];
            int ts = timestamp[i];
            auto site = website[i];
            d[user].emplace_back(ts, site);
        }
        unordered_map<string, int> cnt;
        for (auto& [_, sites] : d) {
            int m = sites.size();
            unordered_set<string> s;
            if (m > 2) {
                ranges::sort(sites);
                for (int i = 0; i < m - 2; ++i) {
                    for (int j = i + 1; j < m - 1; ++j) {
                        for (int k = j + 1; k < m; ++k) {
                            s.insert(sites[i].second + "," + sites[j].second + "," + sites[k].second);
                        }
                    }
                }
            }
            for (const auto& t : s) {
                cnt[t]++;
            }
        }
        int mx = 0;
        string t;
        for (auto& [p, v] : cnt) {
            if (mx < v || (mx == v && t > p)) {
                mx = v;
                t = p;
            }
        }
        return split(t, ',');
    }

private:
    [[nodiscard]] static vector<string> split(const string& s, char c) {
        vector<string> res;
        stringstream ss(s);
        string item;
        while (getline(ss, item, c)) {
            res.push_back(item);
        }
        return res;
    }
};
