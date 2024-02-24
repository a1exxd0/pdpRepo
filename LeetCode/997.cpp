#include<vector>
#include<thread>
#include<iostream>
using namespace std;

/*Easy difficulty but went above and beyond and used multithreading*/

vector<int> inc(const vector<vector<int>> trust, const int n, const int z){
    int tlen = trust.size();
    vector<int> res(n+1, 0);
    for(int i = 0; i < tlen; i++){
        res[trust[i][z]]++;
    }
    return res;
}

class Solution {
public:
    int findJudge(const int n, vector<vector<int>>& trust) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);

        vector<int> trusted;
        std::thread th1([&trusted, trust, n](){
            trusted = inc(trust, n, 1);
        });

        vector<int> trusting;
        std::thread th2([&trusting, trust, n](){
            trusting = inc(trust, n, 0);
        });
        
        th1.join();
        th2.join();

        vector<int> candidates;
        for (int i = 1; i <= n; i++){
            if(trusted[i] == n-1){
                if(trusting[i] == 0){
                    candidates.push_back(i);
                }
            }
        }
        if (candidates.size() != 1) return -1;
        else return candidates[0];
        
    }
};

