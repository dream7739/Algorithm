#include <string>
#include <vector>
#include <set>

using namespace std;

int n = 0;
int ch[10];
set<int> se;

bool isPrime(int num){
    if(num < 2) return false;
    
    for(int i = 2; i*i <= num; i++){
        if(num % i == 0) return false;
    }
    return true;
}

void DFS(string str, string numbers){
    if(str.size() > 0 && isPrime(stoi(str))){
        se.insert(stoi(str));
    }
    
    for(int i = 0; i < n; i++){
        if(ch[i] == 0){
            ch[i] = 1;
            DFS(str+numbers[i], numbers);
            ch[i] = 0;
        }
    }
    
}

int solution(string numbers) {
    int answer = 0;
    n = numbers.size();
    DFS("", numbers);
    answer = se.size();
    return answer;
}
