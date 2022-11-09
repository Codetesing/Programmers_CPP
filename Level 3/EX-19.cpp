#include <string>
#include <algorithm>

using namespace std;

int solution(string s)
{
    int answer = 0;
    
    int n = s.size();

    for(int i = n; i > 0; i--) {
        for(int j = 0; j <= n - i; j++) {
            bool flag = true;
            int left = j, right = j + i - 1;
            
            while(left < right) {
                if(s[left++] != s[right--]) {
                    flag = false;
                    break;
                }
            }
            
            if(flag) {
                answer = i;
                break;
            }
        }
        
        if(answer != 0)
            break;
    }
    
    return answer;
}
