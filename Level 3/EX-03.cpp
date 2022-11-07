#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        return a > b;
    }
};

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    priority_queue<int> pq_max;
    priority_queue<int, vector<int>, cmp> pq_min;
    int cnt = 0;
    
    for(int i = 0; i < operations.size(); i++) {
        char opt = operations[i][0];
        
        if(cnt == 0) {
            while(!pq_min.empty())
                pq_min.pop();
            while(!pq_max.empty())
                pq_max.pop();
        }
        
        if(opt == 'I') {
            int n = stoi(operations[i].substr(2));
            pq_min.push(n);
            pq_max.push(n);
            cnt++;
        }
        
        if(opt == 'D') {
            if(cnt != 0) {
                if(operations[i][2] == '-') {
                    pq_min.pop();
                    cnt--;
                }
                else {
                    pq_max.pop();
                    cnt--;
                }
            }
        }
    }
    
    if(cnt == 0) {
        answer.push_back(0);
        answer.push_back(0);
    }
    
    else {
        answer.push_back(pq_max.top());
        answer.push_back(pq_min.top());
    }
    
    return answer;
}
