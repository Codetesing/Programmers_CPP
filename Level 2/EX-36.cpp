#include <iostream>
using namespace std;

int solution(int n)
{
    int ans = 0;

    for (; n != 0; n /= 2)
        if (n % 2 == 1)
            ans++;
    
    return ans;
}