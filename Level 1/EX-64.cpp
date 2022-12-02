#include <string>
#include <vector>

using namespace std;

int DIV(int a) {
    int i = 1;
    int ans = 0;
    
    for(int i = 1; i * i <= a; i++) {
        if(a % i == 0) {
            if(i * i == a)
                ans += 1;
            else
                ans += 2;
        }
    }
    
    return ans;
}

int solution(int number, int limit, int power) {
    int answer = 0;
    
    for(int i = 1; i <= number; i++) {
        int d = DIV(i);
        
        if(d > limit)
            answer += power;
        else
            answer += d;
    }
    
    return answer;
}
