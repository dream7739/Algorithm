#include <string>
#include <vector>
using namespace std;

string solution(vector<int> numbers, string hand) {
    int l = 10;
    int r = 12;
    int lDis, rDis;
    
    for(int i = 0; i < numbers.size(); i++){
        int num = numbers[i];
        
        if(num == 1 || num == 4 || num == 7){
            l = num;
            answer += "L";
        }else if(num == 3 || num == 6 || num == 9){
            r = num;
            answer += "R";
        }else {
            if(num == 0) num = 11;
            
            lDis = abs(num-l)/3 + abs(num-l)%3;
            rDis = abs(num-r)/3 + abs(num-r)%3;
            
            if(lDis < rDis){
                answer += "L";
                l = num;
            }else if(lDis > rDis){
                answer += "R";
                r = num;
            }else if(lDis == rDis){
                if(hand == "left"){
                    answer += "L";
                    l = num;
                }else if(hand == "right"){
                    answer += "R";
                    r = num;
                }
            }
        }
    }
    
    return answer;
}
