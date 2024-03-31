#include <vector>
using namespace std;

class Solution {
public:
    int trap(const vector<int>& height) {
        int l = 0, r = height.size()-1, lh = -1, rh = -1, res = 0;
        while(l < r){
            if (height[l] < height[r]){
                if (height[l] > lh){
                    lh = height[l];
                } else{
                    res += lh - height[l];
                }
                l++;
            } else{
                if (height[r] > rh){
                    rh = height[r];
                } else{
                    res += rh - height[r];
                }
                r--;
            }
        }
        return res;
    }
};