#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

bool compare(vector<int> a, vector<int> b) {
    return a[0] < b[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    
    sort(jobs.begin(), jobs.end());
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    int cur = 0;
    
    for(int i = 0; i < jobs.size() || !pq.empty();) {
        if(i < jobs.size() && cur >= jobs[i][0]) {
            pq.push(jobs[i++]);
            continue;
        }
        
        if(!pq.empty()) {
            cur += pq.top()[1];
            answer += cur - pq.top()[0];
            pq.pop();
        }
        else
            cur = jobs[i][0];
    }
    
    return answer / jobs.size();
}
