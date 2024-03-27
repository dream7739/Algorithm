#include <iostream>
#include <queue>
using namespace std;

//73. 최대힙(STL priority_queue: 우선순위 큐)

int main(){
    int n;
    priority_queue<int> pq;
    
    while(1){
        cin >> n;
        if(n == -1) break;
        if(n == 0){
            if(pq.empty()) cout << "-1" << "\n";
            else{
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
        else pq.push(n);
    }
    
    return 0;
}

