/**
 * @brief Stack implementation using two queues
 * @intuition Reverse order on push by rotating elements
 * @approach On push, add to q2, then move all q1 elements to q2, swap queues
 * @complexity Time: O(n) push, O(1) others, Space: O(n)
 */

class MyStack final {
private:
  std::queue<int> primary;
  std::queue<int> secondary;

public:
  MyStack() = default;

  auto push(const int x) -> void {
    secondary.push(x);
    while (!primary.empty()) {
      secondary.push(primary.front());
      primary.pop();
    }
    std::swap(primary, secondary);
  }

  [[nodiscard]] auto pop() -> int {
    const int topVal = primary.front();
    primary.pop();
    return topVal;
  }

  [[nodiscard]] auto top() const -> int {
    return primary.front();
  }

  [[nodiscard]] auto empty() const -> bool {
    return primary.empty();
  }
};
