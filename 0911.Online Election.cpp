/**
 * @brief Binary search on precomputed election winners
 * @intuition Precompute winner at each timestamp, then binary search for query
 * @approach Track vote counts and running winner; store winner at each time
 * @complexity Time: O(n) construction, O(log n) per query, Space: O(n)
 */
class TopVotedCandidate final {
public:
    TopVotedCandidate(const vector<int>& persons, const vector<int>& times)
        : times_(times) {
        const int n = static_cast<int>(persons.size());
        wins_.resize(n);
        vector<int> cnt(n);
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            const int p = persons[i];
            ++cnt[p];
            if (cnt[cur] <= cnt[p]) {
                cur = p;
            }
            wins_[i] = cur;
        }
    }

    [[nodiscard]] int q(const int t) const {
        const int i = upper_bound(times_.begin(), times_.end(), t) - times_.begin() - 1;
        return wins_[i];
    }

private:
    vector<int> times_;
    vector<int> wins_;
};
