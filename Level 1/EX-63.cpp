#include <string>
#include <vector>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(int a, int b) {
        return a > b;
    }
};

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;
    priority_queue<int, vector<int>, cmp> pq;
    
    for(int i = 0; i < k && i < score.size(); i++) {
        pq.push(score[i]);
        answer.push_back(pq.top());
    }
    
    for(int i = k; i < score.size(); i++) {
        if(pq.top() < score[i]) {
            pq.pop();
            pq.push(score[i]);
        }
        answer.push_back(pq.top());
    }
    
    return answer;
}
