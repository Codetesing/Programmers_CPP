#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int ind = 0;
    int sum = 0;
    queue<int> bridge;

    while (1)
    {
        if (ind == truck_weights.size())
            return answer + bridge_length;

        answer++;
        
        if (bridge.size() == bridge_length)
        {
            sum -= bridge.front();
            bridge.pop();
        }

        if (sum + truck_weights[ind] <= weight)
        {
            sum += truck_weights[ind];
            bridge.push(truck_weights[ind]);
            ind++;
        }
        else
            bridge.push(0);
    }
}