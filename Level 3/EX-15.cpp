#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> sticker)
{
    int answer =0;
    int n = sticker.size();
    
    if(n == 1)
        return sticker[0];
    
    vector<int> DP(n, 0);
    
    DP[0] = sticker[0];
    DP[1] = sticker[0];
    for(int i = 2; i < n - 1; i++)
        DP[i] = max(DP[i - 2] + sticker[i], DP[i - 1]);
    answer = DP[n - 2];
    
    DP[0] = 0;
    DP[1] = sticker[1];
    for(int i = 2; i < n; i++)
        DP[i] = max(DP[i - 2] + sticker[i], DP[i - 1]);
    answer = max(answer, DP[n - 1]);

    return answer;
}
