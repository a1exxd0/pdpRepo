#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int n = nums.size();
        vector<int> res; res.reserve(n / 2);

        for(int i = 0; i < n; i++){
            const int x = abs(nums[i])-1;
            if (nums[x] < 0){
                res.push_back(x+1);
            } else{
                nums[x] *= -1;
            }
        }
        return res;
    }
};