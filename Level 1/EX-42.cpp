using namespace std;

int solution(int n)
{
    int answer = 0;

    for (int i = 10; n != 0; n /= 10)
        answer += n % 10;

    return answer;
}