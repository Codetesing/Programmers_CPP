#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool compare(pair<string, int> a, pair<string, int> b) {
    return a.second > b.second;
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> play_cnt;
    map<string, vector<pair<int, int>>> song_cnt;
    
    for(int i = 0; i < genres.size(); i++) {
        play_cnt[genres[i]] += plays[i];
        song_cnt[genres[i]].push_back({i, plays[i]});
    }
    
    vector<pair<string, int>> pc(play_cnt.begin(), play_cnt.end());
    sort(pc.begin(), pc.end(), compare);
    for(map<string, vector<pair<int, int>>>::iterator it = song_cnt.begin(); it != song_cnt.end(); it++)
        sort(it->second.begin(), it->second.end(), cmp);
    
    for(int i = 0; i < pc.size(); i++) {
        string g = pc[i].first;
        
        for(int j = 0; j < song_cnt[g].size() && j < 2; j++)
            answer.push_back(song_cnt[g][j].first);
    }
    
    return answer;
}
