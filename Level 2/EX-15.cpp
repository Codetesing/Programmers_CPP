#include <string>
#include <algorithm>

using namespace std;

int solution(string name)
{
    int answer = 0;
    int shift = name.length() - 1;
    for (int i = 0; i < name.length(); i++)
    {
        if (name[i] == 'A')
        {
            int target = i;
            while (target < name.length() && name[target] == 'A')
                target += 1;
            int left = i == 0 ? 0 : i - 1;
            int right = name.length() - target;
            shift = min(shift, left + right + min(left, right));
        }
    }
    answer += shift;
    for (auto c : name)
        answer += min(c - 'A', 'Z' - c + 1);
    return answer;
}