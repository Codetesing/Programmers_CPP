#include <string>
#include <vector>

using namespace std;

int solution(int n, long long l, long long r) {
    int answer = 0;

    for (long long i = l; i <= r; i++) {
        bool flag = true;
        
        if (i % 5 == 3)
            continue;
        
        long long temp = i;
        long long result;
        
        while (1) {
            if(temp % 5 == 0)
                temp = temp / 5;
            else
                temp = (temp / 5) + 1;

            if(temp % 5 == 3) {
                flag = false;
                break;
            }
            else if(temp <= 5) {
                flag = true;
                break;
            }
        }

        if(flag) 
            answer++;
    }

    return answer;
}
