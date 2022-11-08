#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> A, vector<int> B) {
    int answer = 0;
    
    priority_queue<int> pqa(A.begin(), A.end());
    priority_queue<int> pqb(B.begin(), B.end());
    
    while(!pqa.empty() && !pqb.empty()) {
        if(pqa.top() < pqb.top()) {
            pqa.pop();
            pqb.pop();
            answer++;
        }
        else
            pqa.pop();
    }
    
    return answer;
}
