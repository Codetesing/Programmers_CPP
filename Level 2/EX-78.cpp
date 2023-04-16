#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int r1, int r2) {
    long long answer = 0;
    long long r1p = (long long)r1 * (long long)r1;
    long long r2p = (long long)r2 * (long long)r2;
    
    for(long long i = 1; i < r1; i++) {
        long long ip = i * i;
        long long min_y = ceil(sqrt(r1p - ip));
        long long max_y = floor(sqrt(r2p - ip));
        
        answer += max_y - min_y + 1;
    }
    
    for(long long i = r1; i <= r2; i++) {
        long long ip = i * i;
        long long max_y = floor(sqrt(r2p - ip)) + 1;
        answer += max_y;
    }
        
    answer *= 4;
    
    return answer;
}
