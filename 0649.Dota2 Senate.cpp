/**
 * @brief Simulate Dota2 senate voting with ban rights
 * @intuition Use two queues to simulate round-robin banning
 * @approach Track indices, earlier senator bans later one, winner re-enters next round
 * @complexity Time: O(n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static string predictPartyVictory(const string& senate) {
        const int n = senate.size();
        queue<int> qr;
        queue<int> qd;
        
        for (int i = 0; i < n; ++i) {
            if (senate[i] == 'R') {
                qr.push(i);
            } else {
                qd.push(i);
            }
        }
        
        while (!qr.empty() && !qd.empty()) {
            const int r = qr.front();
            const int d = qd.front();
            qr.pop();
            qd.pop();
            
            if (r < d) {
                qr.push(r + n);
            } else {
                qd.push(d + n);
            }
        }
        return qr.empty() ? "Dire" : "Radiant";
    }
};
