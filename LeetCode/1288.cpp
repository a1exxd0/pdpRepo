#include<vector>
#include<iostream>
using namespace std;

//first time union finding
class Solution {
public:
    void coveredBy(const vector<int>& v1, const vector<int>& v2, vector<int>& parent, const int j, const int i){
        //return (v1[0] <= v2[0] && v1[1] >= v2[1]);
        if (v1[0] <= v2[0]){
            if (v1[1] >= v2[1]){
                parent[i] = j;
            }
        } else {
            if (v2[1] >= v1[1]){
                parent[j] = i;
            }
        }
    }
    int removeCoveredIntervals(const vector<vector<int>>& vals) {
        ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
        int n = vals.size();
        vector<int> parent(n);
        for (int i = 0; i < n; i++) parent[i] = i;
        for (int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                if (parent[i] == i){
                    coveredBy(vals[j], vals[i], parent, j, i);
                } 
            }
        }
        int res = 0;
        for(int i = 0; i < n; i++){
            if(parent[i] == i) res++;
        }
        return res;
    }
};