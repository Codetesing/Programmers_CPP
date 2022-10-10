#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string num = "";
string find_num = "";

bool IS_PRIME(long long n)
{
    if (n == 1 || n == 0)
        return false;

    for (long long i = 2; i * i <= n; i++)
        if (n % i == 0)
            return false;

    return true;
}
int solution(int n, int k) {
    int answer = 0;

    for (int i = k; n != 0; n /= k)
        num += (char)((n % k) + '0');

    reverse(num.begin(), num.end());

    for (int i = 0; i < num.size(); i++)
    {
        if (num[i] == '0')
        {
            if(find_num != "")
                if (IS_PRIME(stoll(find_num)))
                    answer++;
            find_num = "";
        }
        else
            find_num += num[i];
    }
    if (find_num != "")
        if (IS_PRIME(stoll(find_num)))
            answer++;
    return answer;
}