#include <string>
#include <vector>

using namespace std;

vector<int> num;
int cnt = 0;

void DFS(int cur, int ind, int target)
{
    if (ind == num.size())
    {
        if (cur == target)
            cnt++;
        return;
    }

    DFS(cur + num[ind], ind + 1, target);
    DFS(cur - num[ind], ind + 1, target);
}

int solution(vector<int> numbers, int target) {
    int answer = 0;

    num = numbers;
    
    DFS(0, 0, target);

    answer = cnt;

    return answer;
}