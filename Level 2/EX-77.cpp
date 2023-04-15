#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> targets) {
    sort(targets.begin(), targets.end());
    int answer = 1, missile = targets[0][1];
    
    for(int i = 1; i < targets.size(); i++) {
        if(targets[i][0] < missile)
            missile = min(missile, targets[i][1]);
        else {
            answer++;
            missile = targets[i][1];
        }
    }
    
    return answer;
}
