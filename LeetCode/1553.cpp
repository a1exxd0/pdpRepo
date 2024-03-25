#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    unordered_map<int, int> mem;

    int minDays(int n) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        mem[0] = 0;
        return rec(n);
    }

    int rec(int n){
        if(n <= 1){
            return n;
        }
        if(mem.find(n) != mem.end()){
            return mem[n];
        } else{
            mem[n] = 1 + min(n%2 + rec(n/2), n%3 + rec(n/3));
            return mem[n];
        }
    }
};