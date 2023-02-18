#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    priority_queue<int, vector<int>> pq; 
    
    for (int r = 0; r < enemy.size(); r++) {
        if (n >= enemy[r]) {
            pq.push(enemy[r]);
            n -= enemy[r];
        }
        else {
            if (k) {
                k--;
                if (!pq.empty()) {
                    int temp = pq.top();
                    pq.pop();
                    if (temp >= enemy[r]) {
                        n += temp - enemy[r];
                        pq.push(enemy[r]);
                    }
                    else pq.push(temp);
                }
            }
            else return r;
        }
    }
    return enemy.size();
}
