#include <vector>
#include <utility>
#include <stack>
using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& tmps) {
        vector<int> res(tmps.size());
        stack<pair<int, int>> ind;
        ind.push(make_pair(tmps[0], 0));
        for(int i = 1; i < tmps.size(); i++){
            if (tmps[i] > tmps[i-1]){
                while(!ind.empty() && tmps[i] > ind.top().first){
                    res[ind.top().second] = i-ind.top().second;
                    ind.pop();
                }
            }
            ind.push(make_pair(tmps[i], i));
        }
        return res;
    }
};