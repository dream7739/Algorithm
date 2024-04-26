#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    int d = 0, p = 0, cnt = 0;
    
    for(int i = n-1; i >= 0; i--){
        //d와 p를 재사용 : d와 p가 0 초과일 때 오는길에 배달/수거가 가능
        //그만큼 요구량이 줄어든다.
        d -= deliveries[i]; //배달 요구량
        p -= pickups[i];    //수거 요구량
        
        while(1){
            if(d >= 0 && p >= 0) break; //배달 요구량을 다 채우면 break
            d += cap;
            p += cap;
            cnt++;
        }
        
        answer += (i+1) * 2 * cnt;
        cnt = 0;
    }
    
    return answer;
}
