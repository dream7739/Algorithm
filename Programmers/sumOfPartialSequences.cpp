#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    vector<int> answer;
    int s = 0, e = 0;
    int sum = sequence[0];
    int subLen = sequence.size() + 1;
    pair<int, int> rslt;
    
    while(s <= e && e < sequence.size()){
        if(sum < k){
            sum += sequence[++e];
        }else if(sum == k){
            if(e - s + 1 < subLen){
                subLen = e - s + 1;
                rslt = { s, e };
            }else if(e - s + 1 == subLen){
                if(s < rslt.first){
                    rslt = { s, e };
                }
            }
            sum -= sequence[s++];
        }else{
            sum -= sequence[s++];
        }
    }
   
    answer.push_back(rslt.first);
    answer.push_back(rslt.second);
    
    return answer;
}
