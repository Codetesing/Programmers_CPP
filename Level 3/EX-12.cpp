#include <vector>

using namespace std;

int solution(int n, vector<int> stations, int w)
{
    int answer = 0;
    int ind = 0;

    for(int i = 1; i <= n;) {
        if(ind < stations.size() && i >= stations[ind] - w) {
            i = stations[ind] + w + 1;
            ind++;
        }
        else {
            i += 2 * w + 1;
            answer++;
        }
    }

    return answer;
}
