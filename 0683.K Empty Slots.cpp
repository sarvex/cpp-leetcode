/**
 * @brief Find earliest day with exactly k empty slots between two blooming flowers
 * @intuition Use BIT to count bloomed flowers in range, check neighbors at each bloom
 * @approach Track bloomed flowers with BIT, check if k empty slots exist between neighbors
 * @complexity Time: O(n log n), Space: O(n)
 */
class BinaryIndexedTree final {
public:
    explicit BinaryIndexedTree(const int n) : n_(n), c_(n + 1) {}

    void update(int x, const int delta) {
        for (; x <= n_; x += x & -x) {
            c_[x] += delta;
        }
    }

    [[nodiscard]] int query(int x) const {
        int s = 0;
        for (; x > 0; x -= x & -x) {
            s += c_[x];
        }
        return s;
    }

private:
    int n_;
    vector<int> c_;
};

class Solution final {
public:
    [[nodiscard]] static int kEmptySlots(const vector<int>& bulbs, const int k) {
        const int n = bulbs.size();
        BinaryIndexedTree tree(n);
        vector<bool> vis(n + 1);
        
        for (int i = 1; i <= n; ++i) {
            const int x = bulbs[i - 1];
            tree.update(x, 1);
            vis[x] = true;
            
            int y = x - k - 1;
            if (y > 0 && vis[y] && tree.query(x - 1) - tree.query(y) == 0) {
                return i;
            }
            y = x + k + 1;
            if (y <= n && vis[y] && tree.query(y - 1) - tree.query(x) == 0) {
                return i;
            }
        }
        return -1;
    }
};
