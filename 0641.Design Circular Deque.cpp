/**
 * @brief Circular deque with fixed capacity using array
 * @intuition Use front pointer and size, compute indices with modulo for wrap-around
 * @approach Maintain front index and size, adjust indices for front/back operations
 * @complexity Time: O(1) per operation, Space: O(k)
 */
class MyCircularDeque final {
public:
    explicit MyCircularDeque(const int k) : capacity_(k), q_(k) {}

    bool insertFront(const int value) {
        if (isFull()) {
            return false;
        }
        if (!isEmpty()) {
            front_ = (front_ - 1 + capacity_) % capacity_;
        }
        q_[front_] = value;
        ++size_;
        return true;
    }

    bool insertLast(const int value) {
        if (isFull()) {
            return false;
        }
        const int idx = (front_ + size_) % capacity_;
        q_[idx] = value;
        ++size_;
        return true;
    }

    bool deleteFront() {
        if (isEmpty()) {
            return false;
        }
        front_ = (front_ + 1) % capacity_;
        --size_;
        return true;
    }

    bool deleteLast() {
        if (isEmpty()) {
            return false;
        }
        --size_;
        return true;
    }

    [[nodiscard]] int getFront() const {
        return isEmpty() ? -1 : q_[front_];
    }

    [[nodiscard]] int getRear() const {
        return isEmpty() ? -1 : q_[(front_ + size_ - 1) % capacity_];
    }

    [[nodiscard]] bool isEmpty() const {
        return size_ == 0;
    }

    [[nodiscard]] bool isFull() const {
        return size_ == capacity_;
    }

private:
    int front_ = 0;
    int size_ = 0;
    int capacity_;
    vector<int> q_;
};
