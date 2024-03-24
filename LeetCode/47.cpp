#include <bits/stdc++.h>

struct VectorHash {
    size_t operator()(const std::vector<int>& vec) const {
        size_t hash = 0;
        for (int i = 0; i < std::min((int)vec.size(), 10); i++) {
            hash ^= std::hash<int>()(vec[i]); // Combine hash of each element
        }
        return hash;
    }
};

class Solution {
public:
    std::unordered_set<std::vector<int>, VectorHash> s;

    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> res;
        dfs(nums, 0, nums.size()-1);
        for(const auto& x: s){
            res.push_back(x);
        }
        return res;
    }

    void dfs(std::vector<int>& nums, int l, int r){
        if (l == r) s.insert(nums);

        for (int i = l; i <= r; i++){
            std::swap(nums[l], nums[i]);
            dfs(nums, l+1, r);
            std::swap(nums[l], nums[i]);
        }
    }
};