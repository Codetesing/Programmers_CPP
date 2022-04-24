#include <string>
#include <vector>

using namespace std;

int DAYS_OF_MONTH(int i)
{
    if (i == 2)
        return 29;
    else if (i == 3)
        return 31;
    else if (i == 4)
        return 30;
    else if (i == 5)
        return 31;
    else if (i == 6)
        return 30;
    else if (i == 7)
        return 31;
    else if (i == 8)
        return 31;
    else if (i == 9)
        return 30;
    else if (i == 10)
        return 31;
    else if (i == 11)
        return 30;
    else if (i == 12)
        return 31;
}

string solution(int a, int b) {
    string answer[] = { "FRI", "SAT", "SUN", "MON", "TUE", "WED", "THU" };
    int day = b - 1;

    for (int i = 1; i < a; i++)
        day += DAYS_OF_MONTH(i);

    return answer[day % 7];
}