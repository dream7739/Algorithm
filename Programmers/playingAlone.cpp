#include <string>
#include <vector>
#include <algorithm>

using namespace std;
int unf[101];
int tb[101];

int Find(int v){
    if(v == unf[v]) return v;
    else return unf[v] = Find(unf[v]);
}

void Union(int a, int b){
    a = Find(a);
    b = Find(b);
    if(a != b) unf[a] = b;
}

int solution(vector<int> cards) {
    int answer = 0;
    int size = cards.size();
    
    for(int i = 0; i < 101; i++){
        unf[i] = i;
    }
    
    for(int i = 0; i < size; i++){
        Union(cards[i], cards[cards[i]-1]);
    }
    
    for(int i = 0; i < size; i++){
        int idx = Find(cards[i]);
        tb[idx]++;
    }
    
    sort(tb, tb + 100, greater<int>());
    answer = tb[0] * tb[1];
    return answer;
    
}
