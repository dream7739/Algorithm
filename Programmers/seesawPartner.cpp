#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int bSearch(int idx, vector<int> w){
    int s = idx;
    int num = w[idx];
    int mid;
    int e = w.size() - 1;
    
    while(s < e){
        mid = (s + e) / 2;
        if(w[mid] > num * 2) return mid;
        else s = mid+1;
    }
    
    return s;
}

long long solution(vector<int> weights) {
    long long answer = 0;
    int n = weights.size();
    int res;
    sort(weights.begin(), weights.end());
    
    for(int i = 0; i < n-1; i++){
        if(i > 0 && weights[i] == weights[i-1]){
            res--;
            answer += res;
            continue;
        }
        int j = bSearch(i, weights);
        res = 0;
        for(; j > i; j--){
            if(weights[i] == weights[j] || weights[i] * 2 == weights[j] ||
               weights[i] * 3 == weights[j] * 2 || weights[i] * 4 == weights[j] * 3){
                res++;
            }
        }
        answer += res;
    }
    
    return answer;
}
