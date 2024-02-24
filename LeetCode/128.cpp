#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return n;
        unordered_set<int> s;
        for(auto x : nums) s.insert(x);
        int res = 0;
        for (auto x: s){
            if(s.find(x-1) == s.end()){
                int curr = x;
                int len = 1;
                while(s.find(curr+1) != s.end()){
                    curr++;
                    len++;
                }
                res = max(res, len);
            }
        }
        return res;
    }
};