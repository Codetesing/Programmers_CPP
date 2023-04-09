#include <string>
#include <vector>
#include <algorithm>

using namespace std;

long long solution(vector<int> sequence) {
    vector<long long> MAX_DP(sequence.size(), 0);
    vector<long long> MIN_DP(sequence.size(), 0);
    
    for(int i = 0; i < sequence.size(); i += 2)
        sequence[i] *= -1;
    
    MAX_DP[0] = MAX_DP[0] > sequence[0] ? MAX_DP[0] : sequence[0];
    for(int i = 1; i < sequence.size(); i++)
        MAX_DP[i] = MAX_DP[i - 1] + sequence[i] > sequence[i] ? MAX_DP[i - 1] + sequence[i] : sequence[i];
        
    long long max_value = *max_element(MAX_DP.begin(), MAX_DP.end());

    MIN_DP[0] = MIN_DP[0] < sequence[0] ? MIN_DP[0] : sequence[0];
    for(int i = 1; i < sequence.size(); i++) 
        MIN_DP[i] = MIN_DP[i - 1] + sequence[i] < sequence[i] ? MIN_DP[i - 1] + sequence[i] : sequence[i];
        
    long long min_value = *min_element(MIN_DP.begin(), MIN_DP.end());
    
    return max(max_value, -1 * min_value);
}
