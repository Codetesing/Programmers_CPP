#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    int answer = 0;

    if (cacheSize == 0)
        return 5 * cities.size();

    vector<string> cache(cacheSize);
    vector<int> visited_num(cacheSize, -1);
    vector<string>::iterator it;

    for (int i = 0; i < cities.size(); i++)
    {
        for (int j = 0; j < cities[i].size(); j++)
            if (isupper(cities[i][j]))
                cities[i][j] = tolower(cities[i][j]);

        it = find(cache.begin(), cache.end(), cities[i]);
        if (it == cache.end())
        {
            int min_ind = min_element(visited_num.begin(), visited_num.end()) - visited_num.begin();
            cache[min_ind] = cities[i];
            visited_num[min_ind] = i;
            answer += 5;
        }
        else
        {
            visited_num[it - cache.begin()] = i;
            answer += 1;
        }
    }

    return answer;
}