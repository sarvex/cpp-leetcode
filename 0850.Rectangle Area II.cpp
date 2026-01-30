/**
 * @brief Segment tree with coordinate compression for rectangle union area
 * @intuition Use line sweep with segment tree to track active vertical segments
 * @approach Compress y-coordinates, sweep x-coordinates left to right. For each
 *           vertical segment, use segment tree to track coverage. Add area between
 *           consecutive x-coordinates times total covered y-length.
 * @complexity Time: O(n^2 log n), Space: O(n)
 */
class Solution final {
    struct Node {
        int l, r, cnt, length;
    };

    class SegmentTree {
        std::vector<Node> tr;
        std::vector<int> nums;

    public:
        explicit SegmentTree(const std::vector<int>& nums) : nums(nums) {
            const int n = static_cast<int>(nums.size()) - 1;
            tr.resize(n << 2);
            build(1, 0, n - 1);
        }

        auto build(int u, int l, int r) -> void {
            tr[u] = {l, r, 0, 0};
            if (l != r) {
                const int mid = (l + r) >> 1;
                build(u << 1, l, mid);
                build(u << 1 | 1, mid + 1, r);
            }
        }

        auto modify(int u, int l, int r, int k) -> void {
            if (tr[u].l >= l && tr[u].r <= r) {
                tr[u].cnt += k;
            } else {
                const int mid = (tr[u].l + tr[u].r) >> 1;
                if (l <= mid) modify(u << 1, l, r, k);
                if (r > mid) modify(u << 1 | 1, l, r, k);
            }
            pushup(u);
        }

        [[nodiscard]] auto query() const -> int {
            return tr[1].length;
        }

    private:
        auto pushup(int u) -> void {
            if (tr[u].cnt) {
                tr[u].length = nums[tr[u].r + 1] - nums[tr[u].l];
            } else if (tr[u].l == tr[u].r) {
                tr[u].length = 0;
            } else {
                tr[u].length = tr[u << 1].length + tr[u << 1 | 1].length;
            }
        }
    };

public:
    [[nodiscard]] static auto rectangleArea(
        const std::vector<std::vector<int>>& rectangles) -> int {
        constexpr int mod = 1'000'000'007;
        const int n = static_cast<int>(rectangles.size());
        std::vector<std::vector<int>> segs(n << 1);
        std::set<int> ts;
        
        int idx = 0;
        for (const auto& e : rectangles) {
            const int x1 = e[0], y1 = e[1], x2 = e[2], y2 = e[3];
            segs[idx++] = {x1, y1, y2, 1};
            segs[idx++] = {x2, y1, y2, -1};
            ts.insert(y1);
            ts.insert(y2);
        }
        
        std::ranges::sort(segs);
        std::unordered_map<int, int> m;
        idx = 0;
        for (const int v : ts) {
            m[v] = idx++;
        }
        
        std::vector<int> nums(ts.begin(), ts.end());
        SegmentTree tree(nums);
        long long ans = 0;
        
        for (std::size_t i = 0; i < segs.size(); ++i) {
            const auto& e = segs[i];
            const int x = e[0], y1 = e[1], y2 = e[2], k = e[3];
            if (i > 0) {
                ans += static_cast<long long>(tree.query()) * (x - segs[i - 1][0]);
            }
            tree.modify(1, m[y1], m[y2] - 1, k);
        }
        
        return static_cast<int>(ans % mod);
    }
};
