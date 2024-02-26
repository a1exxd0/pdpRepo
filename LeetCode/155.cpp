#include<utility>
#include<vector>
using namespace std;

class MinStack {
    vector<pair<int, int>> s;
    int min;
public:
    MinStack() {
        this->min = 2147483647;
    }
    
    void push(int val) {
        s.push_back(make_pair(val, min));
        if (val < min) min = val;
    }
    
    void pop() {
        min = s[s.size()-1].second;
        s.pop_back();
    }
    
    int top() {
        return s[s.size()-1].first;
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */