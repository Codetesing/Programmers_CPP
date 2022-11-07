#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    
    if(n > s)
        answer.push_back(-1);
    else {
        int div = s / n;
        int mod = s % n;
        
        for(int i = 0; i < n; i++)
            answer.push_back(div);
        
        if(mod != 0) {
            for(int i = 0; i < mod; i++)
                answer[answer.size() - 1 - i]++;
        }
    }
    
    return answer;
}
