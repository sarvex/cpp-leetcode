/**
 * @brief Array with snapshot capability using sparse storage
 * @intuition Store only changed values with their snapshot IDs, use binary search for queries
 * @approach For each index, maintain list of (snap_id, value) pairs. On get, binary search
 *           for largest snap_id <= queried snap_id and return its value.
 * @complexity Time: O(log S) for get where S is snaps, O(1) for set/snap, Space: O(n + updates)
 */
class SnapshotArray final {
public:
    SnapshotArray(int length) {
        arr.resize(length);
    }

    void set(int index, int val) {
        arr[index].emplace_back(i, val);
    }

    [[nodiscard]] int snap() {
        return i++;
    }

    [[nodiscard]] int get(int index, int snap_id) const {
        auto it = upper_bound(arr[index].begin(), arr[index].end(), make_pair(snap_id, INT_MAX));
        return it == arr[index].begin() ? 0 : prev(it)->second;
    }

private:
    vector<vector<pair<int, int>>> arr;
    int i = 0;
};
