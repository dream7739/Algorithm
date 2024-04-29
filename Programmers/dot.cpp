#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(int k, int d) {
    long long answer = 0;
    
    for(long long x = 0; x <= d; x += k){
        int y = sqrt((long long) d * d - (long long) x * x);
        answer += (y/k) + 1;
    }
    
    return answer;
}
