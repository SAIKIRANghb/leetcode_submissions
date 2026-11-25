// Last updated: 11/25/2026, 3:44:26 PM
#include <iostream>
#include <functional>
#include <thread>
#include <mutex>
#include <condition_variable>

class FizzBuzz {
private:
    int n;
    int i;
    std::mutex mtx;
    std::condition_variable cv;

public:
    FizzBuzz(int n) : n(n), i(1) {}

    void fizz(function<void()> printFizz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return (i % 3 == 0 && i % 5 != 0) || i > n; });
            if (i > n) break;
            printFizz();
            i++;
            cv.notify_all();
        }
    }

    void buzz(function<void()> printBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return (i % 5 == 0 && i % 3 != 0) || i > n; });
            if (i > n) break;
            printBuzz();
            i++;
            cv.notify_all();
        }
    }

    void fizzbuzz(function<void()> printFizzBuzz) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return (i % 3 == 0 && i % 5 == 0) || i > n; });
            if (i > n) break;
            printFizzBuzz();
            i++;
            cv.notify_all();
        }
    }

    void number(function<void(int)> printNumber) {
        while (true) {
            std::unique_lock<std::mutex> lock(mtx);
            cv.wait(lock, [this] { return (i % 3 != 0 && i % 5 != 0) || i > n; });
            if (i > n) break;
            printNumber(i);
            i++;
            cv.notify_all();
        }
    }
};
