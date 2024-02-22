#include<mutex>
#include<condition_variable>
using namespace std;

class FooBar {
private:
    mutex m;
    condition_variable cv;
    int n;
    bool fooTurn;

public:
    FooBar(int n) {
        this->n = n;
        fooTurn = true;
    }

    //redlined as it involves params from elsewhere, this works in leetcode terminal
    void foo(function<void()> printFoo) {
        
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] {return fooTurn;});
        	// printFoo() outputs "foo". Do not change or remove this line.
        	printFoo();
            fooTurn = false;
            cv.notify_all();
        }
    }

    void bar(function<void()> printBar) {
        for (int i = 0; i < n; i++) {
            unique_lock<mutex> lock(m);
            cv.wait(lock, [this] {return !fooTurn;});
        	// printBar() outputs "bar". Do not change or remove this line.
        	printBar();
            fooTurn = true;
            cv.notify_all();
        	
        	
        }
    }
};