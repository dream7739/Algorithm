#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> solution(vector<int> arr, vector<int> delete_list) {
    vector<int> answer;
    set<int> s;
    
    for(int i = 0; i < delete_list.size(); i++){
        s.insert(delete_list[i]);
    }
    
    for(int i = 0; i < arr.size(); i++){
        if(s.find(arr[i]) == s.end()){
            answer.push_back(arr[i]);
        }
    }
    
    return answer;
}
