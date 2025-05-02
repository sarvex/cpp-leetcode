#include <vector>

using std::vector;

class Solution {
public:
  /**
   * Skip-ahead greedy solution for Gas Station circuit
   * @intuition: Try each station as a start; if you fail at station j, skip all stations between start and j.
   * @approach: For each candidate start, simulate the circuit. If fail, skip ahead to failure point.
   * @complexity: Time O(n), Space O(1)
   */
  int canCompleteCircuit(const vector<int>& gas, const vector<int>& cost) const {
    const auto n = gas.size();
    for (size_t start = 0; start < n; ) {
      int tank = gas[start] - cost[start];
      if (tank < 0) {
        ++start;
        continue;
      }
      size_t idx = (start + 1) % n;
      size_t steps = 1;
      while (steps < n && tank >= 0) {
        tank += gas[idx] - cost[idx];
        idx = (idx + 1) % n;
        ++steps;
      }
      if (tank >= 0 && steps == n) return static_cast<int>(start);
      // If failed, skip all stations between start and idx
      start += steps;
    }
    return -1;
  }
};
