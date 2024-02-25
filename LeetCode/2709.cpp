#include<vector>
#include<unordered_set>
#include<iostream>
#include<algorithm>
using namespace std;

void printElems(unordered_set<int> s){
    cout << "{";
    for (auto x : s){
        cout << x << ", ";
    }
    cout << "}" << endl;
}

vector<int> primeGen(int max){
    vector<int> nums(max+1);
    for(int i = 0; i <= max; i++) nums[i] = i;
    nums[1] = 0;
    for (int i = 4; i <= max; i+=2) nums[i] = 0; 
    for (int i = 3; i <= max; i += 2) { 
        if (nums[i] != 0) { 
            if ((long long int) i * i < INT_MAX){
                for (int j = i * i; j <= max; j += i) { 
                    nums[j] = 0; 
                } 
            }
        } 
    }
    vector<int> res;
    for(auto& x: nums){
        if(x != 0) res.push_back(x);
    }
    return res;
}

int maxelement(vector<int>& nums){
    int res = 0;
    for (auto n: nums){
        if (n == 1) return 0;
        if (n > res) res = n;
    }
    return res;
}

class Solution {
public:
    bool canTraverseAllPairs(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = nums.size();
        if (n == 1) return true;
        if (nums[0] == 1) return false;
        vector<bool> found(n, false);
        found[0] = true;
        
        int maxelem = maxelement(nums);
        if (maxelem == 0) return false;
        vector<int> primes = primeGen(maxelem);
        int ptr = 1;
        while(ptr < n && nums[ptr] == nums[ptr-1]){
            found[ptr] == true;
            ptr++;
        }
        if (ptr == n) return true;
        if (find(nums.begin(), nums.end(), primes[primes.size()-1]) != nums.end()) return false;
        // if n contains 1, false.
        vector<int> pf = findpf(nums[0], primes);
        unordered_set<int> pfactors(pf.begin(), pf.end());
        
        bool iterfound = true;
        while(iterfound){
            iterfound = false;
            //printElems(pfactors);
            for (int i = 1; i < n; i++){
                if (found[i] == false){
                    if(nums[i] == nums[i-1] && found[i-1] == true){
                        iterfound = true;
                        found[i] = true;
                    }
                    else{
                        vector<int> s = findpf(nums[i], primes);
                        //cout << "false found: " << nums[i] << endl; printElems(s);
                        for (auto j : s){
                            if (pfactors.find(j) != pfactors.end()){
                                iterfound = true;
                                found[i] = true;
                                for (auto elem : s){
                                    pfactors.insert(elem);
                                    //cout << "inserting: " << elem << endl;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
        for (auto b: found){
            //cout << b << endl;
            if (b == false) return false;
        }
        return true;
    }

    vector<int> findpf(int num, vector<int>& primes){
        int n = num;
        vector<int> res;
        for (auto& i: primes){
            if (num % i == 0) res.push_back(i);
            if (i > num) break;
        } 
        return res;
    }
};


