
#include<mutex>
#include<condition_variable>
using namespace std;


class H2O {
private:
    mutex m;
    condition_variable cv;
    int counter;

public:
    H2O() {
        this->counter = 0;
    }

    void hydrogen(function<void()> releaseHydrogen) {
        unique_lock<mutex> lock(m);
        while(counter == 2){
            cv.wait(lock);
        }
        counter++;
        // releaseHydrogen() outputs "H". Do not change or remove this line.
        releaseHydrogen();
        cv.notify_all();
    }

    void oxygen(function<void()> releaseOxygen) {
        unique_lock<mutex> lock(m);
        while(counter < 2){
            cv.wait(lock);
        }
        counter = 0;
        // releaseOxygen() outputs "O". Do not change or remove this line.
        releaseOxygen();
        cv.notify_all();
    }
};