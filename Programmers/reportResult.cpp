#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    int n = id_list.size();
    int m = report.size();
    map<string, int> mp;
    vector<vector<int> > chk(n, vector<int>(n, 0));
    vector<int> pause;
    
    for(int i = 0; i < n; i++){
        mp.insert({id_list[i], i});
    }
    
    for(int j = 0; j < m; j++){
        string name = report[j];
        int idx = name.find(" ");
        string a = name.substr(0, idx);
        string b = name.substr(idx + 1);
        
        int ia = mp[a];
        int ib = mp[b];
        
        if(chk[ia][ib] == 0) chk[ia][ib] = 1;
    }
    
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < n; j++){
            cnt += chk[j][i];
        }
        if(cnt >= k){
            pause.push_back(i);
        }
    }
    
    for(int i = 0; i < n; i++){
        int cnt = 0;
        for(int j = 0; j < pause.size(); j++){
            if(chk[i][pause[j]] == 1) cnt++;
        }
        answer.push_back(cnt);
    }
    
    return answer;
}
