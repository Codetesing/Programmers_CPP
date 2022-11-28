#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

struct cmp{
    bool operator()(pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    }
};

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    
    map<int, int> m;
    priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;
    
    for(int i = 0; i < tangerine.size(); i++)
        m[tangerine[i]]++;
    
    for(map<int, int>::iterator it = m.begin(); it != m.end(); it++)
        pq.push({it->first, it->second});
    
    while(k > 0) {
        k -= pq.top().second;
        pq.pop();
        answer++;
    }
    
    return answer;
}
