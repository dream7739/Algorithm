#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int n, int k, vector<int> enemy) {
    int answer = 0;
    int sum = 0, i = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for( ; i < enemy.size(); i++){
        pq.push(enemy[i]);
        
        if(pq.size() > k){
            sum += pq.top();
            pq.pop();
        }
        
        if(sum > n) break;
    }
    
    answer = i;
    return answer;
}
