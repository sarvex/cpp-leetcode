/**
 * @brief Maximum number of courses that can be taken given durations and deadlines
 * @intuition Greedy with priority queue: take courses by deadline, drop longest if over time
 * @approach Sort by deadline, greedily add courses, replace longest course if deadline exceeded
 * @complexity Time: O(n log n), Space: O(n)
 */
class Solution final {
public:
    [[nodiscard]] static int scheduleCourse(vector<vector<int>>& courses) {
        ranges::sort(courses, {}, [](const auto& c) { return c[1]; });
        
        priority_queue<int> pq;
        int s = 0;
        for (const auto& e : courses) {
            const int duration = e[0];
            const int last = e[1];
            pq.push(duration);
            s += duration;
            while (s > last) {
                s -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
};
