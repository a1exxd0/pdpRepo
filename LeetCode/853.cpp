#include <bits/stdc++.h>

using namespace std;

struct pair_compare{
    bool operator()(const pair<int, int>& p1, const pair<int, int>& p2) const {
        return p1.first < p2.first;
    }
};

class Solution {
public:
    int carFleet(int target, const vector<int>& pos, vector<int>& speed) {
        vector<pair<int, int>> pos_index;
        for (int i = 0; i < pos.size(); i++) pos_index.push_back(make_pair(pos[i], i));
        sort(pos_index.begin(), pos_index.end(), pair_compare());
        stack<float> s;
        int res = 0, ptr = 0;
        do {
            float time = (target-pos_index[ptr].first)/ (float) speed[pos_index[ptr].second];
            while(!s.empty() && time >= s.top()){
                s.pop();
            }
            s.push(time);
            ptr++;
        } while(!s.empty() && ptr < pos.size());
        return s.size();
    }
};