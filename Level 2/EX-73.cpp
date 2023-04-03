#include <string>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Job{
public:
    string name;
    int start;
    int time;
    Job(string name, int start, int time) : name(name), start(start), time(time){
    }
};

bool comp(Job a, Job b){
    return a.start<b.start;
}

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    vector<Job> job;
    for(int i=0;i<plans.size();i++){
        int s, t = 0;
        int h = 0, m = 0;
        h += plans[i][1][0]-'0'; h *= 10;
        h += plans[i][1][1]-'0';
        m += plans[i][1][3]-'0'; m *= 10;
        m += plans[i][1][4]-'0';
        s = h*60+m;
        for(int j=0;j<plans[i][2].length();j++){
            t *= 10;
            t += plans[i][2][j]-'0';
        }
        Job temp(plans[i][0], s, t);
        job.push_back(temp);
    }
    sort(job.begin(),job.end(), comp);
    job.push_back(Job("", 1500, 0));
    stack<Job> work;
    for(int i=0;i<job.size()-1;i++){
        int j = i + 1;
        if(job[i].start+job[i].time <= job[j].start){
            answer.push_back(job[i].name);
            int now = job[i].start + job[i].time;
            while(work.size()!=0){
                if(now + work.top().time <= job[j].start){
                    answer.push_back(work.top().name);
                    now += work.top().time;
                    work.pop();
                }else{
                    work.top().time -= job[j].start - now;
                    break;
                }
            }
        }else{
            job[i].time -= job[j].start- job[i].start;
            work.push(job[i]);
        }
    }
    while(work.size()!=0){
        answer.push_back(work.top().name);
        work.pop();
    }
    return answer;
}
