#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int solution(vector<vector<string>> book_time) {
    int answer = 1;
    vector<pair<int, int>> v;
    
    for(int i = 0; i < book_time.size(); i++){
        string s = book_time[i][0];
        string e = book_time[i][1];
        
        int stHour = (s[0] - '0') * 10 + (s[1] - '0');
        int stMinute = (s[3] - '0') * 10 + (s[4] - '0');
        
        int endHour = (e[0] - '0') * 10 + (e[1] - '0');
        int endMinute = (e[3] - '0') * 10 + (e[4] - '0');
        
        v.push_back({ stHour * 60 + stMinute, endHour * 60 + endMinute});
    }
    
    sort(v.begin(), v.end());
    priority_queue<int, vector<int>, greater<int> > pq;
    
    pq.push(v[0].second);
    for(int i = 1; i < v.size(); i++){
        if(pq.size() && v[i].first  >= pq.top()+ 10){
            pq.pop();
            pq.push(v[i].second);
        }else{
            pq.push(v[i].second);
            answer++;
        }
    }
    
    
    return answer;
}
