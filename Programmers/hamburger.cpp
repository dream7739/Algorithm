#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> st;
    
    for(int i = 0; i < ingredient.size(); i++){
        st.push_back(ingredient[i]);
        int size = st.size();
        if(size >= 4){
            if(st[size-4] == 1 && st[size-3] == 2 &&
               st[size-2] == 3 && st[size-1] == 1){
                answer++;
                st.erase(st.end()-4, st.end());
            }
        }
    }
    return answer;
}
