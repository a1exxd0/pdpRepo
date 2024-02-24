#include<vector>
#include<unordered_set>
#include<queue>
using namespace std;


// compares 3rd elem of 2 arrays to construct a lowest-first priority queue
struct Compare {
    bool operator()(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] > v2[2];
    }
};

class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {

        //3 vec, sort on last, min heap.
        priority_queue<vector<int>, vector<vector<int>>, Compare> pq;
        for(auto v: meetings){
            pq.push(v);
            //cout << "push: " << pq.top()[0] << ", " << pq.top()[1] << endl;
        }
        unordered_set<int> s({0, firstPerson});
        int tempTime = 0;
        unordered_set<int> tempSet;

        while(pq.size() != 0){
            //cout << "checking: " << pq.top()[0] << ", " << pq.top()[1] << endl;
            if(tempTime == pq.top()[2]){
                if (s.find(pq.top()[0]) != s.end()){
                    //cout << "eq temp time, "<< pq.top()[0] << ", " << pq.top()[1] << endl;
                    if (tempSet.find(pq.top()[0]) != tempSet.end()
                        || tempSet.find(pq.top()[1]) != tempSet.end()){
                        //cout << "tempset insert" << endl;
                        s.insert(tempSet.begin(), tempSet.end());
                    }
                    s.insert(pq.top()[1]);
                    pq.pop();
                }
                else if(s.find(pq.top()[1]) != s.end()){
                    //cout << "eq temp time, "<< pq.top()[0] << ", " << pq.top()[1] << endl;
                    if (tempSet.find(pq.top()[0]) != tempSet.end()
                        || tempSet.find(pq.top()[1]) != tempSet.end()){
                        //cout << "tempset insert" << endl;
                        s.insert(tempSet.begin(), tempSet.end());
                    }
                    s.insert(pq.top()[0]);
                    pq.pop();
                }
                else{
                    tempSet.insert(pq.top()[0]);
                    tempSet.insert(pq.top()[1]);
                    pq.pop();
                }
            }
            else{
                tempTime = pq.top()[2];
                tempSet.clear();
                tempSet.insert(pq.top()[0]);
                tempSet.insert(pq.top()[1]);
                if (s.find(pq.top()[0]) != s.end()){
                    //cout << pq.top()[0] << ", " << pq.top()[1] << endl;
                    s.insert(pq.top()[1]);
                    pq.pop();
                }
                else if(s.find(pq.top()[1]) != s.end()){
                    //cout << pq.top()[0] << ", " << pq.top()[1] << endl;
                    s.insert(pq.top()[0]);
                    pq.pop();
                }
                else{
                    pq.pop();
                }
            } 
        }
        vector<int> res;
        for(auto x : s){
            res.push_back(x);
        }
        return res;
    }
};