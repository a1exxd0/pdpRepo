#include <bits/stdc++.h>
using namespace std;

/**
 * WORKS ON EARLIER CPP VERSION
*/

constexpr array<bool, 1001> sieve() {
    array<bool, 1001> primes{};

    for (size_t i = 2; i < 1001; ++i) {
        if (primes[i]) {
            for (size_t j = i + i; j < 1001; j += i) {
                primes[j] = true;
            }
        }
    }

    return primes;
}

constexpr auto p = sieve();

constexpr array<int, 168> prime_add(){
    array<int, 168> v; 
    int ptr = 0;
    for (int i = 2; i < 1001; i++){
        if (p[i] == false){
            v[ptr] = i; ptr++;
        }
    }
    return v;
}

constexpr array<int, 168> primes = prime_add();

class Solution {

    int prev;
public:

    constexpr Solution() : prev(0) {}

    // pick a minimal prime that makes num-prime as small as possible above prev
    int pickOptimal(int num){
        int l = 0, r = 167, curr = 0;
        const int optimal = num-prev-1;
        while (l <= r){
            const int mid = (l+r) /2;
            if (primes[mid] <= optimal) {
                curr = primes[mid];
                l = mid+1;
            } else{
                r = mid-1;
            }
        }
        return curr;
    }

    bool primeSubOperation(vector<int>& nums) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        const int n = nums.size();
        for (int i = 0; i < n; i++){
            nums[i] -= pickOptimal(nums[i]);
            prev = nums[i];
            if (i > 0 && nums[i] <= nums[i-1]){
                return false;
            }
        }
        return true;
    }
};
