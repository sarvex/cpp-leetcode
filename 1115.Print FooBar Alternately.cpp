/**
 * @brief Synchronize two threads to alternately print "foo" and "bar" using semaphores
 * @intuition Use semaphores to enforce alternating execution between foo and bar
 * @approach Initialize foo semaphore to 1 (can start), bar to 0. After printing foo, signal bar.
 *           After printing bar, signal foo. Repeat n times.
 * @complexity Time: O(n), Space: O(1)
 */
#include <semaphore.h>

class FooBar final {
private:
    int n;
    sem_t f, b;

public:
    FooBar(int n) {
        this->n = n;
        sem_init(&f, 0, 1);
        sem_init(&b, 0, 0);
    }

    void foo(function<void()> printFoo) {
        for (int i = 0; i < n; i++) {
            sem_wait(&f);
            printFoo();
            sem_post(&b);
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            sem_wait(&b);
            printBar();
            sem_post(&f);
        }
    }
};
