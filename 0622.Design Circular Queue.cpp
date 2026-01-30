/**
 * @brief Circular queue with fixed capacity using array
 * @intuition Use front pointer and size to track queue state in circular buffer
 * @approach Maintain front index and size, compute indices with modulo
 * @complexity Time: O(1) per operation, Space: O(k)
 */
class MyCircularQueue final {
public:
    explicit MyCircularQueue(const int k) : capacity_(k), q_(k) {}

    bool enQueue(const int value) {
        if (isFull()) {
            return false;
        }
        const int idx = (front_ + size_) % capacity_;
        q_[idx] = value;
        ++size_;
        return true;
    }

    bool deQueue() {
        if (isEmpty()) {
            return false;
        }
        front_ = (front_ + 1) % capacity_;
        --size_;
        return true;
    }

    [[nodiscard]] int Front() const {
        if (isEmpty()) {
            return -1;
        }
        return q_[front_];
    }

    [[nodiscard]] int Rear() const {
        if (isEmpty()) {
            return -1;
        }
        const int idx = (front_ + size_ - 1) % capacity_;
        return q_[idx];
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
