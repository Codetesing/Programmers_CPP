#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 5;
    vector<int> num_clothes(n + 2, 1);
    num_clothes[0] = 1;
    num_clothes[n + 1] = 1;

    for (int i = 0; i < lost.size(); i++)
        num_clothes[lost[i]]--;
    for (int i = 0; i < reserve.size(); i++)
        num_clothes[reserve[i]]++;

    for(int i = 1; i <= n; i++)
        if (num_clothes[i] == 2)
        {
            if (num_clothes[i - 1] == 0)
            {
                num_clothes[i - 1]++;
                num_clothes[i]--;
            }
            else if (num_clothes[i + 1] == 0)
            {
                num_clothes[i + 1] ++;
                num_clothes[i]--;
            }
        }
    
    for (int i = 1; i <= n; i++)
        if (num_clothes[i] != 0)
            answer++;

    return answer;
}