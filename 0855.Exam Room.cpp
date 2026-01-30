/**
 * @brief Ordered set with custom comparator for exam room seating
 * @intuition Track intervals between seated students; always choose interval with max distance
 * @approach Maintain intervals sorted by distance (max first). When seating, split the best
 *           interval. When leaving, merge adjacent intervals.
 * @complexity Time: O(log n) per operation, Space: O(n)
 */
class ExamRoom final {
    int n;
    std::set<std::pair<int, int>, std::function<bool(const std::pair<int, int>&, 
                                                      const std::pair<int, int>&)>> ts;
    std::unordered_map<int, int> left;
    std::unordered_map<int, int> right;

    [[nodiscard]] auto dist(const std::pair<int, int>& p) const -> int {
        const auto [l, r] = p;
        if (l == -1 || r == n) return r - l - 1;
        return (r - l) >> 1;
    }

    auto add(std::pair<int, int> s) -> void {
        ts.insert(s);
        left[s.second] = s.first;
        right[s.first] = s.second;
    }

    auto del(std::pair<int, int> s) -> void {
        ts.erase(s);
        left.erase(s.second);
        right.erase(s.first);
    }

public:
    explicit ExamRoom(int n) : n(n), ts([this](const std::pair<int, int>& a, 
                                                const std::pair<int, int>& b) {
        const int d1 = dist(a), d2 = dist(b);
        return d1 == d2 ? a.first < b.first : d1 > d2;
    }) {
        add({-1, n});
    }

    [[nodiscard]] auto seat() -> int {
        const auto s = *ts.begin();
        int p = (s.first + s.second) >> 1;
        if (s.first == -1) {
            p = 0;
        } else if (s.second == n) {
            p = n - 1;
        }
        del(s);
        add({s.first, p});
        add({p, s.second});
        return p;
    }

    auto leave(int p) -> void {
        const int l = left[p], r = right[p];
        del({l, p});
        del({p, r});
        add({l, r});
    }
};
