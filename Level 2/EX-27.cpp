#include <vector>

using namespace std;

vector<long long> solution(vector<long long> numbers)
{
    vector<long long> answer;

    for (int i = 0; i < numbers.size(); i++)
    {
        long long temp = 1;

        while ((numbers[i] & temp) > 0)
            temp = temp << 1;
        
        answer.push_back(numbers[i] + temp - (temp >> 1));
    }

    return answer;
}