#include <string>
#include <vector>
#include <queue>
#include <stack>

using namespace std;

struct Plan{
    string name;
    int time;
    int playTime;
    
    Plan(string a, string b, string c){
        name = a;
        time = 60 * stoi(b.substr(0 , 2)) + stoi(b.substr(3, 5));
        playTime = stoi(c);
    }
    
    Plan(string a, int b, int c){
        name = a;
        time = b;
        playTime = c;
    }
    
    bool operator <(const Plan &p)const{
        return time > p.time;
    }
};

vector<string> solution(vector<vector<string>> plans) {
    vector<string> answer;
    priority_queue<Plan> pq;
    stack<Plan> st;
    
    for(int i = 0; i < plans.size(); i++){
        pq.push(Plan(plans[i][0], plans[i][1], plans[i][2]));
    }
    
    int currentTime = 0; //현재 시간
    
    while(!pq.empty()){
        Plan plan = pq.top(); //가장 앞 시간을 가진 plan
        
        //미뤄둔 작업을 현재 작업과 비교
        //미뤄둔 작업은 진행중이던 과제를 끝냈을 때 남은 시간이 있어야 함
        if(!st.empty()){
            Plan stPlan = st.top();
            st.pop();
            
            if(plan.time > currentTime){
                pq.push(Plan(stPlan.name, currentTime, stPlan.playTime));
                continue;
            }else{
                st.push(Plan(stPlan.name, currentTime, stPlan.playTime));
            }
        }
        
        pq.pop();
        Plan nextPlan = pq.top();
        currentTime = plan.time + plan.playTime; //현재시간 = 작업시간시간 + 소요시간
        
        
        //현재 시간이 다음 시작시간보다 작으면 작업을 끝낼 수 있다(answer에 추가)
        //현재 시간이 다음 시작시간보다 크면 작업을 미루어두어야 한다.(stack에 추가)
        //다음 작업이 시작되면 currentTime은 다음 작업의 시작시간이 되며
        //이전 작업은 stack에 들어가면서 남은 시간만큼 저장한다
        if(currentTime <= nextPlan.time){
            answer.push_back(plan.name);
        }else if(currentTime > nextPlan.time){
            currentTime = nextPlan.time;
            st.push(Plan(plan.name, plan.time, plan.playTime - (nextPlan.time - plan.time)));
        }
    }
    
    
    while(!st.empty()){
        Plan stPlan = st.top();
        st.pop();
        answer.push_back(stPlan.name);
    }
    
    return answer;
}

