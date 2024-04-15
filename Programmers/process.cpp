#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    int cnt = 1;
    queue<pair<int, int>> q;
    priority_queue<int> pq;
    
    for(int i = 0; i < priorities.size(); i++){
        q.push({i, priorities[i]});
        pq.push(priorities[i]);
    }
    
    while(1){
        int t1= pq.top();
        pair<int, int> t2 = q.front();
        q.pop();
        
        if(t1 == t2.second){
            if(location == t2.first){
                answer = cnt;
                break;
            }else{
                cnt++;
                pq.pop();
            }
        }else if(t1 != t2.second){
            q.push(t2);
        }
        
    }
    
    return answer;
}
