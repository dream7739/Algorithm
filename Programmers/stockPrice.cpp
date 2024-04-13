#include <string>
#include <stack>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer(prices.size());
    stack<int> s;
    int size = prices.size();
    
    for(int i = 0; i < size - 1; i++){
        while(!s.empty() && prices[s.top()] > prices[i]){
            answer[s.top()] = i-s.top();
            s.pop();
        }
        s.push(i);
    }
    
    while(!s.empty()){
        answer[s.top()] = (size - 1) - s.top();
        s.pop();
    }
    
    answer[size-1] = 0;
    return answer;
}
