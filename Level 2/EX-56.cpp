#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(int x = 0; x <= d; x += k) {
        int y = static_cast<int>(sqrt(pow(d, 2) - pow(x, 2)));
        answer += y / k + 1;
    }
    
    return answer;
}
