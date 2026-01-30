/**
 * @brief Peeking iterator with cached next element
 * @intuition Cache the next element when peek is called
 * @approach Store peeked element and flag, return cached value on next()
 * @complexity Time: O(1) per operation, Space: O(1)
 */

/*
 * Below is the interface for Iterator, which is already defined for you.
 * **DO NOT** modify the interface for Iterator.
 *
 *  class Iterator {
 *		struct Data;
 * 		Data* data;
 *  public:
 *		Iterator(const vector<int>& nums);
 * 		Iterator(const Iterator& iter);
 *
 * 		// Returns the next element in the iteration.
 *		int next();
 *
 *		// Returns true if the iteration has more elements.
 *		bool hasNext() const;
 *	};
 */

class PeekingIterator final : public Iterator {
public:
    explicit PeekingIterator(const vector<int>& nums)
        : Iterator(nums), hasPeeked_(false), peekedElement_(0) {}

    [[nodiscard]] int peek() {
        if (!hasPeeked_) {
            peekedElement_ = Iterator::next();
            hasPeeked_ = true;
        }
        return peekedElement_;
    }

    int next() {
        if (!hasPeeked_) {
            return Iterator::next();
        }
        hasPeeked_ = false;
        return peekedElement_;
    }

    [[nodiscard]] bool hasNext() const {
        return hasPeeked_ || Iterator::hasNext();
    }

private:
    bool hasPeeked_;
    int peekedElement_;
};
