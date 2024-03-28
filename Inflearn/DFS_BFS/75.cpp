#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

//75. 최대 수입 스케쥴(priority_queue 응용문제)

struct Data{
    int money;
    int when;
    Data(int a, int b){
        money = a;
        when = b;
    }
    bool operator<(const Data &b)const{
        return when > b.when;
    }
};

int main(){
    vector<Data> T;
    priority_queue<int> pq;
    int n, a, b, res = 0, max = -2147483647;
    
    cin >> n;
    
    for(int i = 0; i < n; i++){
        cin >> a >> b;
        T.push_back(Data(a, b));
        if(max < b) max = b;
    }
    
    sort(T.begin(), T.end());
    int j = 0;
    for(int i = max; i >= 1; i--){
        for( ; j < n; j++){
            if(T[j].when < i) break;
            pq.push(T[j].money);
        }
        
        if(!pq.empty()){
            res += pq.top();
            pq.pop();
        }
    }
    
    cout << res << "\n";
    return 0;
}
