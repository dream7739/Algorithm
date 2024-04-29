#include <string>
#include <vector>
#include <algorithm>
#include <map>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    int cnt = 0;
    map<int, int> m;
    vector<int> v;
    
    for(int i = 0; i < tangerine.size(); i++){
        int num = tangerine[i];
        m[num]++;
    }
    
    for(const auto &mp : m){
        v.push_back(mp.second);
    }
    
    sort(v.begin(), v.end(), greater<>());
    
    for(int i = 0; i < v.size(); i++){
        cnt += v[i];
        answer++;
        if(cnt >= k) break;
    }
    
    return answer;
}
