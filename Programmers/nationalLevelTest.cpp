#include <string>
#include <vector>
#include <algorithm>

using namespace std;

struct student{
    int idx;
    int rank;
    bool attendance;
    
    student(int a, int b, bool c){
        idx = a;
        rank = b;
        attendance = c;
    }
    
    bool operator<(const student &s)const{
        return rank < s.rank;
    }
};

int solution(vector<int> rank, vector<bool> attendance) {
    vector<student> arr;
    int answer = 0;
    int size = rank.size();
    
    for(int i = 0; i < size; i++){
        arr.push_back(student(i, rank[i], attendance[i]));
    }
    sort(arr.begin(), arr.end());
    
    vector<int> res;
    
    //상위 3명 뽑힌 학생 번호
    for(int i = 0; i < size; i++){
        if(res.size() == 3) break;
        student s = arr[i];
        if(s.attendance == false) continue;
        else{
            res.push_back(s.idx);
        }
    }
    
    answer = 10000 * res[0] + 100 * res[1] + res[2];
    return answer;
}
