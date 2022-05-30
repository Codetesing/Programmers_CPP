#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    int ind = -1;

    for (int i = 0; i < number.size() - k; i++)
    {
        char max_n = ' ';
        for(int j = ind + 1; j <= k + i; j++)
            if (max_n < number[j])
            {
                ind = j;
                max_n = number[j];
            }
        answer += max_n;
    }

    return answer;
}