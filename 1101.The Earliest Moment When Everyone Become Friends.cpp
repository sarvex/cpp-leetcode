/**
 * @brief Union-Find to find when all people become connected
 * @intuition Sort logs by timestamp and use union-find to merge friend groups until everyone is connected
 * @approach Sort logs chronologically, then process each log using union-find. When two people
 *           from different groups become friends, merge their groups. Track remaining groups until only one remains.
 * @complexity Time: O(n log n + m * alpha(n)), Space: O(n) where m is number of logs
 */
class Solution final {
public:
    [[nodiscard]] static int earliestAcq(vector<vector<int>>& logs, int n) {
        ranges::sort(logs);
        vector<int> p(n);
        iota(p.begin(), p.end(), 0);
        auto find = [&](this auto&& find, int x) -> int {
            return p[x] == x ? x : p[x] = find(p[x]);
        };
        for (const auto& log : logs) {
            int x = find(log[1]);
            int y = find(log[2]);
            if (x != y) {
                p[x] = y;
                --n;
            }
            if (n == 1) {
                return log[0];
            }
        }
        return -1;
    }
};
