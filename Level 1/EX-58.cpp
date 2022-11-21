#include <string>
#include <vector>

using namespace std;

int solution(int a, int b, int n) {
    int answer = 0;
    
    while(n >= a) {
        int i = (n / a) * b;
        answer += i;
        n = i + n % a;
    }
    
    return answer;
}
