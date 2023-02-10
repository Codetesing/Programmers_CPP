#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct compare {
    bool operator()(int a, int b) {
        return a > b;
    }
};

bool cmp(vector<string> a, vector<string> b) {
    return a < b;
}

int ttoi(string a) {
    int h = stoi(a.substr(0, 2));
    int m = stoi(a.substr(3, 2)) + 10;

    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    int answer = 0;
    priority_queue<int, vector<int>, compare> pq;

    sort(book_time.begin(), book_time.end(), cmp);

    for (int i = 0; i < book_time.size(); i++) {
        int start = ttoi(book_time[i][0]) - 10;
        int end = ttoi(book_time[i][1]);

        if (pq.empty() || pq.top() > start)
            answer++;
        else
            pq.pop();

        pq.push(end);
    }

    return answer;
}
