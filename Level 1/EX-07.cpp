#include <string>
#include <vector>

using namespace std;

int solution(vector<int> numbers) {
    int answer = 0;

    vector<bool> visited(10, false);

    for (int i = 0; i < numbers.size(); i++)
        visited[numbers[i]] = true;

    for (int i = 0; i < 10; i++)
        if (!visited[i])
            answer += i;

    return answer;
}