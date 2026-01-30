/**
 * @brief Union-Find with lexicographically smallest representative
 * @intuition Group equivalent characters; always point to smallest in group
 * @approach Union-Find where parent is always the smaller character
 * @complexity Time: O(n * alpha), Space: O(1)
 */
class Solution final {
public:
    [[nodiscard]] static string smallestEquivalentString(
        const string& s1,
        const string& s2,
        const string& baseStr) {
        
        array<int, 26> p;
        iota(p.begin(), p.end(), 0);
        
        function<int(int)> find = [&](const int x) -> int {
            if (p[x] != x) {
                p[x] = find(p[x]);
            }
            return p[x];
        };
        
        for (size_t i = 0; i < s1.size(); ++i) {
            const int a = s1[i] - 'a', b = s2[i] - 'a';
            const int pa = find(a), pb = find(b);
            if (pa < pb) {
                p[pb] = pa;
            } else {
                p[pa] = pb;
            }
        }
        
        string res;
        for (const char a : baseStr) {
            res += static_cast<char>(find(a - 'a') + 'a');
        }
        return res;
    }
};
