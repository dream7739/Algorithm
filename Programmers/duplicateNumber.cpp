#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<int> array, int n) {
    int answer = 0;
    map<int, int> m;
    
    for(int i = 0; i < array.size(); i++){
        int num = array[i];
        m[num]++;
    }
    
    answer = m[n];
    return answer;
}
