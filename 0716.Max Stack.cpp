/**
 * @brief Max stack with O(log n) operations using list and multimap
 * @intuition Doubly linked list for O(1) removal, multimap for O(log n) max lookup
 * @approach List stores values, multimap maps values to list iterators
 * @complexity Time: O(log n) for all operations, Space: O(n)
 */
class MaxStack final {
public:
    MaxStack() = default;

    void push(const int x) {
        stack_.push_back(x);
        valueToIter_.insert({x, std::prev(stack_.end())});
    }

    [[nodiscard]] int pop() {
        auto it = std::prev(stack_.end());
        const int result = *it;
        auto mapIt = std::prev(valueToIter_.upper_bound(result));
        valueToIter_.erase(mapIt);
        stack_.erase(it);
        return result;
    }

    [[nodiscard]] int top() const {
        return stack_.back();
    }

    [[nodiscard]] int peekMax() const {
        return valueToIter_.rbegin()->first;
    }

    [[nodiscard]] int popMax() {
        auto mapIt = std::prev(valueToIter_.end());
        auto listIt = mapIt->second;
        const int result = *listIt;
        valueToIter_.erase(mapIt);
        stack_.erase(listIt);
        return result;
    }

private:
    std::list<int> stack_;
    std::multimap<int, std::list<int>::iterator> valueToIter_;
};
