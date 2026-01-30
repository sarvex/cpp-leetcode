/**
 * @brief Minimum stickers to spell target using character counts
 * @intuition BFS with bitmask representing covered characters
 * @approach State is bitmask of covered positions, try each sticker to extend
 * @complexity Time: O(2^n * m * k) where m is stickers, k is sticker length, Space: O(2^n)
 */
class Solution final {
public:
    [[nodiscard]] static int minStickers(const vector<string>& stickers, const string& target) {
        const int n = target.size();
        queue<int> q{{0}};
        vector<bool> vis(1 << n);
        vis[0] = true;
        
        for (int ans = 0; !q.empty(); ++ans) {
            for (int m = q.size(); m > 0; --m) {
                const int cur = q.front();
                q.pop();
                
                if (cur == (1 << n) - 1) {
                    return ans;
                }
                
                for (const auto& s : stickers) {
                    int cnt[26]{};
                    int nxt = cur;
                    for (const char c : s) {
                        ++cnt[c - 'a'];
                    }
                    for (int i = 0; i < n; ++i) {
                        const int j = target[i] - 'a';
                        if ((cur >> i & 1) == 0 && cnt[j] > 0) {
                            nxt |= 1 << i;
                            --cnt[j];
                        }
                    }
                    if (!vis[nxt]) {
                        vis[nxt] = true;
                        q.push(nxt);
                    }
                }
            }
        }
        return -1;
    }
};
