/**
 * @brief Synchronize three threads to print sequence 0102030405... using semaphores
 * @intuition Use semaphores to coordinate zero, odd, and even number printing in sequence
 * @approach Zero thread prints 0, then signals odd or even based on next number. Odd/even threads
 *           print their number and signal zero thread to continue.
 * @complexity Time: O(n), Space: O(1)
 */
#include <semaphore.h>

class ZeroEvenOdd final {
private:
    int n;
    sem_t z, e, o;

public:
    ZeroEvenOdd(int n) {
        this->n = n;
        sem_init(&z, 0, 1);
        sem_init(&e, 0, 0);
        sem_init(&o, 0, 0);
    }

    void zero(function<void(int)> printNumber) {
        for (int i = 0; i < n; ++i) {
            sem_wait(&z);
            printNumber(0);
            if (i % 2 == 0) {
                sem_post(&o);
            } else {
                sem_post(&e);
            }
        }
    }

    void even(function<void(int)> printNumber) {
        for (int i = 2; i <= n; i += 2) {
            sem_wait(&e);
            printNumber(i);
            sem_post(&z);
        }
    }

    void odd(function<void(int)> printNumber) {
        for (int i = 1; i <= n; i += 2) {
            sem_wait(&o);
            printNumber(i);
            sem_post(&z);
        }
    }
};
