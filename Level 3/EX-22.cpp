#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 1000001

int solution(vector<int> a) {
    int answer = 0;
    int left[MAX];
    int right[MAX];
    int n = a.size();
    
    left[0] = a[0];
    for(int i = 1; i < n; i++)
        left[i] = min(a[i], left[i - 1]);
    
    right[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; i--)
        right[i] = min(a[i], right[i + 1]);
    
    for(int i = 0; i < n; i++)
        if(a[i] == left[i] || a[i] == right[i])
            answer++;
    
    return answer;
}
