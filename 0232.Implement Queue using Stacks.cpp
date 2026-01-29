/**
 * @brief Queue implementation using two stacks
 * @intuition Move elements between stacks to reverse order
 * @approach Use input stack for push, output stack for pop/peek with lazy transfer
 * @complexity Time: O(1) amortized, Space: O(n)
 */
#include <stack>

class MyQueue final {
private:
  std::stack<int> inputStack;
  std::stack<int> outputStack;

  auto transfer() -> void {
    if (outputStack.empty()) {
      while (!inputStack.empty()) {
        outputStack.push(inputStack.top());
        inputStack.pop();
      }
    }
  }

public:
  MyQueue() = default;

  auto push(int x) -> void {
    inputStack.push(x);
  }

  [[nodiscard]] auto pop() -> int {
    transfer();
    const int front = outputStack.top();
    outputStack.pop();
    return front;
  }

  [[nodiscard]] auto peek() -> int {
    transfer();
    return outputStack.top();
  }

  [[nodiscard]] auto empty() const -> bool {
    return inputStack.empty() && outputStack.empty();
  }
};
