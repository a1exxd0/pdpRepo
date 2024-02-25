#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

struct hashFunction  
{ 
  size_t operator()(const vector<int>  
                    &myVector) const 
  { 
    std::hash<int> hasher; 
    size_t answer = 0; 
      
    for (int i : myVector)  
    { 
      answer ^= hasher(i) + 0x9e3779b9 +  
                (answer << 6) + (answer >> 2); 
    } 
    return answer; 
  } 
}; 
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_set<vector<int>, hashFunction> s;
        int l=0;
        while(l < n-2){
            if(l != 0 && nums[l-1] == nums[l]){
                l++;
            }
            else{
                int target = -1 * nums[l];
                int left = l + 1;
                int right = n - 1;
                while(left < right){
                    if(nums[left] + nums[right] == target){
                        s.insert({nums[l], nums[left], nums[right]});
                        left++; right--;
                    } 
                    else if(nums[left] + nums[right] < target){
                        left++;
                    } else{
                        right--;
                    }
                }
                l++;
            }
            
        }
        vector<vector<int>> res(s.begin(), s.end());
        return res;
    }
};