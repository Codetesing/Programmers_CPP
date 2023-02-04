#include <string>
#include <vector>
#include <stack>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer(numbers.size(), 0);
    stack<int> idx;
    
    for(int i = 0; i < numbers.size(); i++) {
        if(idx.empty() || numbers[i] < numbers[i - 1])
            idx.push(i);
        else {
            while(!idx.empty() && numbers[idx.top()] < numbers[i]) {
                answer[idx.top()] = numbers[i];
                idx.pop();
            }
            
            idx.push(i);
        }
    }
    
    while(!idx.empty()) {
        answer[idx.top()] = -1;
        idx.pop();
    }
    
    return answer;
}
