#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int GCD(int a, int b) {
    if(b == 1)
        return 1;
    
    if(a % b == 0)
        return b;
    else
        return GCD(b, a % b);
}

bool cmp(int a, int b) {
    return a > b;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
    int answer = 0;
    
    sort(arrayA.begin(), arrayA.end(), cmp);
    
    int GCD_A = arrayA[0], GCD_B = arrayB[0];
    for(int i = 1; i < arrayA.size(); i++) {
        GCD_A = GCD(max(GCD_A, arrayA[i]), min(GCD_A, arrayA[i]));
        GCD_B = GCD(max(GCD_B, arrayB[i]), min(GCD_B, arrayB[i]));
    }
    if(GCD_A == 1 && GCD_B == 1)
            return 0;
    
    vector<int> CD_A, CD_B;
    for(int i = GCD_A; i >= 2; i--)
        if(GCD_A % i == 0)
            CD_A.push_back(i);
    for(int i = GCD_B; i >= 2; i--)
        if(GCD_B % i == 0)
            CD_B.push_back(i);
    
    for(int i = 0; i < CD_A.size(); i++) {
        bool flag = true;
        for(int j = 0; j < arrayB.size(); j++)
            if(arrayB[j] % CD_A[i] == 0){
                flag = false;
                break;
            }
        if(flag) {
            answer = CD_A[i];
            break;
        }
    }
    
    for(int i = 0; i < CD_B.size(); i++) {
        bool flag = true;
        for(int j = 0; j < arrayA.size(); j++)
            if(arrayA[j] % CD_B[i] == 0){
                flag = false;
                break;
            }
        if(flag) 
            return max(answer, CD_B[i]);
    }
}
