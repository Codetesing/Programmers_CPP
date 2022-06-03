#include <string>
#include <vector>

using namespace std;

int solution(string word) {
    int answer = word.length();
    int n[] = { 781, 156, 31, 6, 1 };
    string alpha = "AEIOU";
    
    for (int i = 0; i < word.length(); i++)
        answer += n[i] * alpha.find(word[i]);

    return answer;
}