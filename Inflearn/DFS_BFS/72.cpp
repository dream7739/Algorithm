#include <iostream>
#include <queue>
using namespace std;

//72. 공주 구하기(큐 자료구조)

int main(){
    int n, k, x;
    queue<int> q;
    cin >> n >> k;
    
    for(int i = 1; i <= n; i++){
        q.push(i);
    }
    
    while(q.size() > 1){
        for(int i = 1; i <= k; i++){
            x = q.front();
            q.pop();
            if(i != k) q.push(x);
        }
    }
    
    cout << q.front() << "\n";
    return 0;
}

