#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    int ind = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();

    return "김서방은 " + to_string(ind) + "에 있다";
}