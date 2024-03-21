#include <string>
#include <vector>

using namespace std;
int answer = 0;

void DFS(int L, vector<int> &numbers, int target, int sum){
    if(L == numbers.size()){
        if(target == sum) answer++;
    }else{
        DFS(L+1, numbers, target, sum + numbers[L]);
        DFS(L+1, numbers, target, sum - numbers[L]);
    }
}

int solution(vector<int> numbers, int target) {
    DFS(0, numbers, target, 0);
    return answer;
}
