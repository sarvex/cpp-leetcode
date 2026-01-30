/**
 * @brief Find invalid transactions based on amount and location rules
 * @intuition Transaction invalid if amount > 1000 or same name in different city within 60 minutes
 * @approach Parse transactions, group by name. Check amount threshold and cross-reference with
 *           same-name transactions for city/time conflicts.
 * @complexity Time: O(n^2), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static vector<string> invalidTransactions(const vector<string>& transactions) {
        unordered_map<string, vector<tuple<int, string, int>>> d;
        unordered_set<int> idx;
        for (int i = 0; i < transactions.size(); ++i) {
            vector<string> e = split(transactions[i], ',');
            string name = e[0];
            int time = stoi(e[1]);
            int amount = stoi(e[2]);
            string city = e[3];
            d[name].emplace_back(time, city, i);
            if (amount > 1000) {
                idx.insert(i);
            }
            for (auto& [t, c, j] : d[name]) {
                if (c != city && abs(time - t) <= 60) {
                    idx.insert(i);
                    idx.insert(j);
                }
            }
        }
        vector<string> ans;
        for (int i : idx) {
            ans.emplace_back(transactions[i]);
        }
        return ans;
    }

private:
    [[nodiscard]] static vector<string> split(const string& s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> res;
        while (getline(ss, item, delim)) {
            res.emplace_back(item);
        }
        return res;
    }
};
