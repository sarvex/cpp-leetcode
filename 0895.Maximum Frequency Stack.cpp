/**
 * @brief Stack with maximum frequency pop using priority queue
 * @intuition Pop element with highest frequency; ties broken by most recent push
 * @approach Use priority queue with (frequency, timestamp, value). On push, increment
 *           frequency and add to queue. On pop, get top element, decrement frequency.
 * @complexity Time: O(log n) per operation, Space: O(n)
 */
class FreqStack final {
    std::unordered_map<int, int> cnt;
    std::priority_queue<std::tuple<int, int, int>> pq;
    int ts = 0;

public:
    FreqStack() = default;

    auto push(int val) -> void {
        ++cnt[val];
        pq.emplace(cnt[val], ++ts, val);
    }

    [[nodiscard]] auto pop() -> int {
        auto [freq, timestamp, val] = pq.top();
        pq.pop();
        --cnt[val];
        return val;
    }
};
