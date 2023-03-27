#include <string>
#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0, max_len = 0;
    
    for(int i = 0; i < section.size(); i++)
        if(max_len < section[i]) {
            answer++;
            max_len = section[i] + m - 1;
        }    
    
    return answer;
}
