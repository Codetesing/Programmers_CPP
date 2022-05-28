#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;

    int n = brown / 2;
    for (int i = 1; i <= n; i++)
    {
        int temp = n - i;
        if (i * (temp - 2) == yellow)
        {
            answer.push_back(temp);
            answer.push_back(i + 2);
            break;
        }
    }

    return answer;
}