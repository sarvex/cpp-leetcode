/**
 * @brief Synchronize three threads to print in order using mutex locks
 * @intuition Use mutex locks to enforce execution order: first unlocks second, second unlocks third
 * @approach Initialize locks for second and third functions as locked. First function releases
 *           second's lock after completion, second releases third's lock after completion.
 * @complexity Time: O(1), Space: O(1)
 */
class Foo final {
private:
    mutex m2, m3;

public:
    Foo() {
        m2.lock();
        m3.lock();
    }

    void first(function<void()> printFirst) {
        printFirst();
        m2.unlock();
    }

    void second(function<void()> printSecond) {
        m2.lock();
        printSecond();
        m3.unlock();
    }

    void third(function<void()> printThird) {
        m3.lock();
        printThird();
    }
};
