#include <string>
#include <vector>

using namespace std;

int user = 0;
int price = 0;
vector<int> percent;
int arr[4] = {10, 20, 30, 40};

void DFS(vector<vector<int>> users, vector<int> emoticons){
    if(percent.size() == emoticons.size()){
        int price_tmp = 0;
        int user_tmp = 0;
        
        for(int i = 0; i < users.size(); i++){
            int p = 0;
            
            for(int j = 0; j < emoticons.size(); j++){
                if(percent[j] >= users[i][0]){
                    p = p + emoticons[j] * (100 - percent[j]) / 100;
                }
            }
            
            if(p >= users[i][1]){
                user_tmp++;
            }else{
                price_tmp += p;
            }
            
        }
        
        if(user_tmp > user){
            user = user_tmp;
            price = price_tmp;
        }else if(user_tmp == user && price_tmp > price){
            price = price_tmp;
        }
        
        return;
        
    }
    
    for(int i = 0; i < 4; i++){
        percent.push_back(arr[i]);
        DFS(users, emoticons);
        percent.pop_back();
    }
}

vector<int> solution(vector<vector<int>> users, vector<int> emoticons) {
    vector<int> answer;
    DFS(users, emoticons);
    answer.push_back(user);
    answer.push_back(price);
    return answer;
}
