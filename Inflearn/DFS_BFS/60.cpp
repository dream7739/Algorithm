#include <iostream>
#include <string>
using namespace std;

//60. 합이 같은 부분집합(DFS)

int n;
int arr[11];
int total = 0;
bool flag = false;

void DFS(int L, int sum){
    if(sum >(total/2)) return;
    if(L == n+1){
        if(flag == true) return;
        if(sum == (total-sum)){
            flag = true;
        }
    }else{
        DFS(L+1, sum+arr[L]);
        DFS(L+1, sum);
    }
}
   
int main(){
    cin >> n;
    
    for(int i = 1; i <= n; i++){
        cin >> arr[i];
        total += arr[i];
    }
    DFS(1, 0);
    if(flag) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    return 0;
}
