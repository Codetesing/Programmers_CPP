#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<string> seoul) {
    int ind = find(seoul.begin(), seoul.end(), "Kim") - seoul.begin();

    return "�輭���� " + to_string(ind) + "�� �ִ�";
}