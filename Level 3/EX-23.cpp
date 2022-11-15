#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define DIV 1000000007
#define MAX 100001

int solution(int n, vector<int> money) {
    int answer = 0;
    int DP[MAX] = {0};
    
    sort(money.begin(), money.end());
    
    DP[0] = 1;
    for(int i = 0; i < money.size(); i++)
        for(int j = money[i]; j <= n; j++)
            DP[j] = (DP[j] + DP[j - money[i]]) % DIV;
        
    answer = DP[n];
    
    return answer;
}
