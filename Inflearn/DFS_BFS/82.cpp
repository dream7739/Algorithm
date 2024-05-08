#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//82. 순열 구하기(DFS)

int a[20], res[20], ch[20];
int n, r, cnt = 0;

void DFS(int L){
    if(L == r){
        cnt++;
        for(int j = 0; j < L; j++){
            cout << res[j] << " ";
        }
        cout << endl;
    }else {
        for(int i = 0; i < n; i++){
            if(ch[i] == 0){
                res[L] = a[i];
                ch[i] = 1;
                DFS(L+1);
                ch[i] = 0;
            }
        }
    }
}

int main(){
    cin >> n >> r;
    
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    
    DFS(0);
    cout << cnt << endl;
    return 0;
}
