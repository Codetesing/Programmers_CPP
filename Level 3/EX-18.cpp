#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(int n, vector<int> times) {
    long long answer = 0;
    
    sort(times.begin(), times.end());
    
    int size = times.size();
    long long min_time = 1;
    long long max_time = (long long)times[size - 1] * n;
    
    while(min_time <= max_time) {
        long long mid_time = (min_time + max_time) / 2;
        long long cnt = 0;
        
        for(int i = 0; i < size; i++)
            cnt += mid_time / times[i];
        
        if(cnt >= n) {
            max_time = mid_time - 1;
            answer = mid_time;
        }
        else
            min_time = mid_time + 1;
    }
    
    return answer;
}
