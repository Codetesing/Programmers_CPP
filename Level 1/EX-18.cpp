#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;
    string temp = "";
    
    for (int i = 3; n != 0; n /= i)
        temp += (n % 3) + '0';

    for (int i = temp.size() - 1, j = 1; i >= 0; i--, j *= 3)
        answer += (temp[i] - '0') * j;

    return answer;
}