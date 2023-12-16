//
//  1157.cpp
//  PS
//
//  Created by 홍정민 on 2023/12/16.
//

#include <iostream>
#include <string>
using namespace std;

int main(){
    string str;
    int max = 0;
    int idx = -1;
    int arr[26] = {0, };
    
    cin >> str;
    
    for(int i = 0; i < str.size(); i++){
        str[i] = toupper(str[i]);
        arr[str[i]-'A'] += 1;
    }
    
    for(int i = 0; i < 26; i++){
        if(max < arr[i]){
            max = arr[i];
            idx = i;
        }
    }
    
    for(int i = 0; i < 26; i++){
        if(i == idx) continue;
        if(arr[i] == arr[idx]){
            cout << '?';
            return 0;
        }
    }
    
    cout << (char)(idx+'A');
    return 0;
    
}
