#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

typedef struct car {
    int s;
    int e;
} car;

struct compare {
    bool operator()(car a, car b){
        return a.s > b.s;
    }
};

int solution(vector<vector<int>> routes) {
    int answer = 0;
    priority_queue<car, vector<car>, compare> pq;
    
    for(int i = 0; i < routes.size(); i++)
        pq.push({routes[i][0], routes[i][1]});
    
    int start = pq.top().s;
    int end = pq.top().e;
    pq.pop(); answer++;

    while(!pq.empty()) {
        int ns = pq.top().s;
        int ne = pq.top().e;
        pq.pop();
        
        if(end < ns) {
            start = ns;
            end = ne;
            answer++;
        }
        else {
            start = max(start, ns);
            end = min(end, ne);
        }
    }
    
    return answer;
}
