#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> alpha(26, -1);
    
    for(int i = 0; i < s.length(); i++) {
        int prev = alpha[s[i] - 'a'];
        
        if(prev == -1)
            answer.push_back(prev);
        else
            answer.push_back(i - prev);
        
        alpha[s[i] - 'a'] = i;
    }
    
    return answer;
}
