// Last updated: 11/25/2026, 3:44:44 PM
#include <iostream>
#include <mutex>
#include <condition_variable>
#include <functional>

using namespace std;

class ZeroEvenOdd {
private:
    int n;
    int current;
    mutex mtx;
    condition_variable cv;

public:
    ZeroEvenOdd(int n) : n(n), current(1) {}

    // printNumber(x) outputs "x", where x is an integer.
    void zero(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (current <= 2 * n) {
            cv.wait(lock, [this] { return current > 2 * n || current % 2 != 0; });
            if (current <= 2 * n) {
                printNumber(0);
                current++;
                cv.notify_all();
            }
        }
         cv.notify_all();
    }

    void even(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (current <= 2 * n) {
            cv.wait(lock, [this] { return current > 2 * n || (current % 2 == 0 && current % 4 == 0); });
            if (current <= 2 * n) {
                printNumber(current / 2);
                current++;
                cv.notify_all();
            }
        }
         cv.notify_all();
    }

    void odd(function<void(int)> printNumber) {
        unique_lock<mutex> lock(mtx);
        while (current <= 2 * n) {
            cv.wait(lock, [this] { return current > 2 * n || (current % 2 == 0 && current % 4 != 0); });
            if (current <= 2 * n) {
                printNumber((current + 1) / 2);
                current++;
                cv.notify_all();
            }
        }
         cv.notify_all();
    }
};
