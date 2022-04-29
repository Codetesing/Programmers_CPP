#include <string>

using namespace std;

int solution(string s)
{
	int answer = 0;
	int temp = 0, prev = 0;

	for (int i = 0; i < s.size(); i++)
	{

		if (s[i] == '1')
		{
			if (s[i + 1] == '0')
			{
				i++;
				temp = 10;
			}
			else
				temp = 1;
		}
		else
			temp = s[i] - '0';

		if (s[i + 1] == 'D')
			temp *= temp;
		else if (s[i + 1] == 'T')
			temp *= temp * temp;
		i++;

		if (s[i + 1] == '*')
		{
			answer += prev;
			temp *= 2;
			i++;
		}
		else if (s[i + 1] == '#')
		{
			temp *= -1;
			i++;
		}

		answer += temp;
		prev = temp;
	}

	return answer;
}