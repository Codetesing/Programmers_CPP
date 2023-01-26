#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    int mod = 10;
    
    while(storey != 0) {
        if(storey % mod > 5) {
            answer += 10 - (storey % mod);
            storey /= mod;
            storey++;
        }
        else if(storey % mod < 5) {
            answer += storey % mod;
            storey /= mod;
        }
        else {
            answer += 5;
            
            if(storey / mod % mod < 5) {
                storey /= mod;
            }
            else {
                storey /= mod;
                storey++;
            }
        }
    }
    
    return answer;
}
