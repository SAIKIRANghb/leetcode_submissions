// Last updated: 11/25/2026, 3:44:51 PM
#include <semaphore.h>
#include <functional>

class H2O {
private:
    sem_t h_sem;
    sem_t o_sem;
    int h_count;

public:
    H2O() {
        sem_init(&h_sem, 0, 2); // Allow 2 hydrogen atoms
        sem_init(&o_sem, 0, 1); // Allow 1 oxygen atom
        h_count = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        sem_wait(&h_sem); // Wait for a hydrogen slot to be available
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        h_count++;

        if (h_count == 2) { // If we have 2 hydrogens, signal oxygen
            sem_post(&o_sem);
        }
    }

    void oxygen(function<void()> releaseOxygen) {
        sem_wait(&o_sem); // Wait for two hydrogens to be ready
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        h_count = 0;
        sem_post(&h_sem); // Signal the next hydrogen atoms
        sem_post(&h_sem);
    }
};
