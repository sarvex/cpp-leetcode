/**
 * @brief Segment tree with Boyer-Moore voting for subarray majority queries
 * @intuition Use segment tree to find candidate majority element, verify with binary search
 * @approach Build segment tree storing (candidate, count) using Boyer-Moore merge. For queries,
 *           get candidate from tree then verify actual count using binary search on positions.
 * @complexity Time: O(n) build, O(log^2 n) per query, Space: O(n)
 */
class Node final {
public:
    int l = 0, r = 0;
    int x = 0, cnt = 0;
};

using pii = pair<int, int>;

class SegmentTree final {
public:
    SegmentTree(const vector<int>& nums) : nums(nums) {
        const int n = nums.size();
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) {
            tr[i] = new Node();
        }
        build(1, 1, n);
    }

    [[nodiscard]] pii query(int u, int l, int r) const {
        if (tr[u]->l >= l && tr[u]->r <= r) {
            return {tr[u]->x, tr[u]->cnt};
        }
        int mid = (tr[u]->l + tr[u]->r) >> 1;
        if (r <= mid) {
            return query(u << 1, l, r);
        }
        if (l > mid) {
            return query(u << 1 | 1, l, r);
        }
        auto left = query(u << 1, l, r);
        auto right = query(u << 1 | 1, l, r);
        if (left.first == right.first) {
            left.second += right.second;
        } else if (left.second >= right.second) {
            left.second -= right.second;
        } else {
            right.second -= left.second;
            left = right;
        }
        return left;
    }

private:
    vector<Node*> tr;
    vector<int> nums;

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l == r) {
            tr[u]->x = nums[l - 1];
            tr[u]->cnt = 1;
            return;
        }
        int mid = (l + r) >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }

    void pushup(int u) {
        if (tr[u << 1]->x == tr[u << 1 | 1]->x) {
            tr[u]->x = tr[u << 1]->x;
            tr[u]->cnt = tr[u << 1]->cnt + tr[u << 1 | 1]->cnt;
        } else if (tr[u << 1]->cnt >= tr[u << 1 | 1]->cnt) {
            tr[u]->x = tr[u << 1]->x;
            tr[u]->cnt = tr[u << 1]->cnt - tr[u << 1 | 1]->cnt;
        } else {
            tr[u]->x = tr[u << 1 | 1]->x;
            tr[u]->cnt = tr[u << 1 | 1]->cnt - tr[u << 1]->cnt;
        }
    }
};

class MajorityChecker final {
public:
    MajorityChecker(const vector<int>& arr) : tree(new SegmentTree(arr)) {
        for (int i = 0; i < arr.size(); ++i) {
            d[arr[i]].push_back(i);
        }
    }

    [[nodiscard]] int query(int left, int right, int threshold) const {
        int x = tree->query(1, left + 1, right + 1).first;
        auto l = lower_bound(d.at(x).begin(), d.at(x).end(), left);
        auto r = lower_bound(d.at(x).begin(), d.at(x).end(), right + 1);
        return r - l >= threshold ? x : -1;
    }

private:
    unordered_map<int, vector<int>> d;
    SegmentTree* tree;
};
