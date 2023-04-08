#include <string>
#include <vector>
#include <queue>

using namespace std;

typedef struct seq {
    int cnt;
    int left;
    int right;
} seq;

struct compare {
    bool operator()(seq a, seq b) {
        if(a.cnt == b.cnt)
            return a.left > b.left;
        else
            return a.cnt > b.cnt;
    }
};

vector<int> solution(vector<int> sequence, int k) {
    int n = sequence.size();
    vector<int> answer;
    int sequence_sum = 0, right = 0;
    priority_queue<seq, vector<seq>, compare> pq;
    
    for(int i = 0; i < n; i++) {
        while(sequence_sum < k && right < n)
            sequence_sum += sequence[right++];
        
        if(sequence_sum == k)
            pq.push({right - i, i, right - 1});
        
        sequence_sum -= sequence[i];
    }
    
    answer.push_back(pq.top().left);
    answer.push_back(pq.top().right);
    
    return answer;
}
