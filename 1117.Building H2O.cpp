/**
 * @brief Synchronize hydrogen and oxygen threads to form H2O molecules using semaphores
 * @intuition Two hydrogen atoms must bond before one oxygen can be released
 * @approach Use semaphore to allow 2 hydrogen, track count. When 2 hydrogen collected, signal oxygen.
 *           Oxygen releases and resets, allowing next 2 hydrogen.
 * @complexity Time: O(1) per molecule, Space: O(1)
 */
#include <semaphore.h>

class H2O final {
private:
    sem_t h, o;
    int st;

public:
    H2O() {
        sem_init(&h, 0, 2);
        sem_init(&o, 0, 0);
        st = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h);
        releaseHydrogen();
        ++st;
        if (st == 2) {
            sem_post(&o);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o);
        releaseOxygen();
        st = 0;
        sem_post(&h);
        sem_post(&h);
    }
};
