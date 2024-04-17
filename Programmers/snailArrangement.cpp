#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n, 0));
    int num = 1, sign = 1;
    int x = 0, y = 0;
    
    for(int i = 0; i < n; i++){
        answer[x][y] = num++;
        y += sign;
    }
    
    y-= 1;
    
    for(int i = n-1; i > 0; i--){
        for(int j = 0; j < i; j++){
            x += sign;
            answer[x][y] = num++;
        }
        sign *= -1;
        for(int k = 0; k < i; k++){
            y += sign;
            answer[x][y] = num++;
        }
    }
    
    return answer;
}
